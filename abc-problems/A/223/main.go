package main

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x < 100 {
		fmt.Println("No")
		return
	}

	if x%100 == 0 {
		fmt.Println("Yes")
		return
	} else {
		fmt.Println("No")
		return
	}
}
