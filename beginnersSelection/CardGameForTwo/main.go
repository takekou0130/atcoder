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
		var a_n int
		fmt.Scanf("%d", &a_n)
		arr = append(arr, a_n)
	}
	// 降順にソート
	sort.Sort(sort.Reverse(sort.IntSlice(arr)))
	var alice, bob int
	for i := 0; i < n; i++ {
		// 偶数番目はalice、奇数番目はbob
		if i%2 == 0 {
			alice += arr[i]
		} else {
			bob += arr[i]
		}
	}
	fmt.Println(alice - bob)
}
