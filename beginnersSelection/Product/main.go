package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)
	if isEven(a) || isEven(b) {
		fmt.Println("Even")
	} else {
		fmt.Println("Odd")
	}
}

func isEven(i int) bool {
	return i%2 == 0
}
