package main

import "fmt"

func main() {
	var x, y int
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	rest := y - x
	if rest <= 0 {
		fmt.Println(0)
		return
	}
	fmt.Println((rest-1)/10 + 1)
}
