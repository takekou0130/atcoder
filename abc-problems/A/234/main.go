package main

import "fmt"

func main() {
	var t int
	fmt.Scanf("%d", &t)
	result := exec(exec(exec(t)+t) + exec(exec(t)))
	fmt.Println(result)
}

func exec(x int) int {
	return x*x + 2*x + 3
}
