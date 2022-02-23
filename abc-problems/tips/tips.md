# Go で競技プログラミングをするときの TIPS

## 文字列を分割する

```go
arr := strings.Split(s, "")
```

## max min

math.Max や math.Min は引数が float64 なのでキャストが必要になり面倒。
自前で int に対する max や min を用意しておくのがよい?

```go
func max(slice []int) int {
  var result int
  for _, v := range slice {
    if result < v {
      result = v
    }
  }
  return result
}

func min(slice []int, default int) int {
  result := default
  for _, v := range slice {
    if result > v {
      result = v
    }
  }
  return result
}
```

## 文字を一文字区切りで読み込む

```go
import (
	"bufio"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)
	a := nextInt()
	b := nextInt()
	c := nextInt()
}
```
