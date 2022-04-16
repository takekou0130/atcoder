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
	var arr [100001]int
	sc.Split(bufio.ScanWords)
	for i := 0; i < 4*n-1; i++ {
		input := nextInt()
		arr[input]++
	}

	for idx, value := range arr {
		if value == 3 {
			fmt.Println(idx)
		}
	}
}
