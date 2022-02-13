package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a, b, x int
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)
	fmt.Scanf("%d", &x)

	max_d := intLength(x)
	for d := max_d; d > 0; d-- {
		rest_cost := x - b*d
		if rest_cost <= 0 {
			continue
		}

		if rest_cost/a < 1 {
			continue
		}

	}
	fmt.Println(0)
}

func intLength(n int) int {
	return len(strconv.Itoa(n))
}
