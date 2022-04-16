package main

import (
	"fmt"
)

func main() {
	var i int
	fmt.Scanf("%d", &i)
	var arr []int
	for n := 0; n < 3; n++ {
		arr = append([]int{i % 10}, arr...)
		i /= 10
	}
	result := 100*arr[0] + 10*arr[1] + 1*arr[2]
	result += 100*arr[1] + 10*arr[2] + 1*arr[0]
	result += 100*arr[2] + 10*arr[0] + 1*arr[1]
	fmt.Println(result)
}
