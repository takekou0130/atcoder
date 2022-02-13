package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	var arr []int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var d_n int
		fmt.Scanf("%d", &d_n)
		arr = append(arr, d_n)
	}

	// 餅を大きい順に並べる
	sort.Sort(sort.Reverse(sort.IntSlice(arr)))

	var diag int = 101
	var count int

	for _, d_mochi := range arr {
		if d_mochi < diag {
			diag = d_mochi
			count++
		}
	}

	fmt.Println(count)
}
