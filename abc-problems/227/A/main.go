package main

import "fmt"

func main() {
	var n, k, a int
	fmt.Scan(&n)
	fmt.Scan(&k)
	fmt.Scan(&a)

	r := (k + a - 1) % n
	if r == 0 {
		fmt.Println(n)
		return
	}
	fmt.Println(r)
}
