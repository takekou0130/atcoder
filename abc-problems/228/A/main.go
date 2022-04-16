package main

import "fmt"

func main() {
	var s, t, x int
	fmt.Scan(&s)
	fmt.Scan(&t)
	fmt.Scan(&x)

	start := 0
	end := 24

	if s < t {
		if timeIn(s, t, x) {
			fmt.Println("Yes")
			return
		}
		fmt.Println("No")
		return
	} else {
		if timeIn(s, end, x) || timeIn(start, t, x) {
			fmt.Println("Yes")
			return
		}
		fmt.Println("No")
		return
	}
}

// start <= target < endの関係になっているか判定
func timeIn(start, end, target int) bool {
	if start <= target && target < end {
		return true
	}
	return false
}
