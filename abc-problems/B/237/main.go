package main

import "fmt"

func main() {
	var h, w int
	fmt.Scan(&h)
	fmt.Scan(&w)
	var a [][]int
	for i := 1; i <= h; i++ {
		var inArr []int
		for j := 1; j <= w; j++ {
			var input int
			fmt.Scan(&input)
			inArr = append(inArr, input)
		}
		a = append(a, inArr)
	}

	for i := 0; i < w; i++ {
		for j := 0; j < h; j++ {
			fmt.Print(a[j][i])
			if j == h-1 {
				fmt.Print("\n")
			} else {
				fmt.Print(" ")
			}
		}

	}
}
