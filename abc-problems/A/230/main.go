package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	if n < 10 {
		fmt.Printf("AGC00%d\n", n)
		return
	}
	if n < 42 {
		fmt.Printf("AGC0%d\n", n)
		return
	}
	fmt.Printf("AGC0%d\n", n+1)
}
