package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)

	var result int
	for num := 1; num <= n; num++ {
		if calcSum(num, a, b) {
			result += num
		}
	}
	fmt.Println(result)
}

func calcSum(num, min, max int) bool {
	splited := strings.Split(strconv.Itoa(num), "")
	var sum int
	for _, v := range splited {
		j, _ := strconv.Atoi(v)
		sum += j
	}
	return min <= sum && sum <= max
}
