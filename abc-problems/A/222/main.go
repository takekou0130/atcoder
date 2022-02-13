package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	var arr []int
	for i := 0; i < 4; i++ {
		arr = append([]int{n % 10}, arr...)
		n /= 10
	}
	var res string
	for _, v := range arr {
		res += strconv.Itoa(v)
	}
	fmt.Println(res)
}
