package main

import (
	"bufio"
	"fmt"
	"math"
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
	var arr [][2]int
	sc.Split(bufio.ScanWords)

	for i := 0; n > i; i++ {
		x := nextInt()
		y := nextInt()
		arr = append(arr, [2]int{x, y})
	}

	var result int
	for idx, pos := range arr {
		for i := idx + 1; len(arr) > i; i++ {
			calc := (pos[0]-arr[i][0])*(pos[0]-arr[i][0]) + (pos[1]-arr[i][1])*(pos[1]-arr[i][1])
			if calc > result {
				result = calc
			}
		}
	}
	fmt.Println(math.Sqrt(float64(result)))
}
