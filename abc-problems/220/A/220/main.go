package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	for i := a; i <= b; i++ {
		if i%c == 0 {
			fmt.Println(i)
			return
		}
	}

	fmt.Println(-1)
}
