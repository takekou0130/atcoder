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
		var tmp int
		fmt.Scanf("%d", &tmp)
		arr = append(arr, tmp)
	}

	var maxArray []int
	for _, num := range arr {
		maxArray = append(maxArray, calcMax(num))
	}
	fmt.Println(min(maxArray))
}

func calcMax(num int) int {
	var count int
	for {
		if num%2 == 0 && num != 0 {
			num = num / 2
			count++
		} else {
			break
		}
	}
	return count
}

func min(s []int) int {
	sort.IntSlice(s).Sort()
	return s[0]
}
