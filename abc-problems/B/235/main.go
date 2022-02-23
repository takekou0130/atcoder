package main

import (
	"bufio"
	"fmt"
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
	var n int
	fmt.Scan(&n)
	sc.Split(bufio.ScanWords)
	var h int
	for i := 0; i < n; i++ {
		nextH := nextInt()
		if nextH > h {
			h = nextH
		} else {
			break
		}
	}
	fmt.Println(h)
}
