package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	var arr []int
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		arr = append(arr, a)
	}
	var pizza [361]bool
	pizza[0] = true
	pizza[360] = true
	pos := 0
	for _, v := range arr {
		pos = (pos + v) % 360
		pizza[pos] = true
	}

	start := 0
	var result []int
	for idx, v := range pizza {
		if v {
			result = append(result, idx-start)
			start = idx
		}
	}
	fmt.Println(max(result))
}

func max(slice []int) int {
	var result int
	for _, v := range slice {
		if result < v {
			result = v
		}
	}
	return result
}
