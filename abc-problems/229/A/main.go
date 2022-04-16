package main

import (
	"fmt"
	"strings"
)

func main() {
	var s1, s2 string
	fmt.Scanf("%s", &s1)
	fmt.Scanf("%s", &s2)
	row1 := strings.Split(s1, "")
	row2 := strings.Split(s2, "")
	var count int
	for _, v := range row1 {
		if v == "#" {
			count++
		}
	}
	for _, v := range row2 {
		if v == "#" {
			count++
		}
	}
	if count >= 3 {
		fmt.Println("Yes")
		return
	}

	if row1[0] == "#" && row2[1] == "#" {
		fmt.Println("No")
		return
	}

	if row1[1] == "#" && row2[0] == "#" {
		fmt.Println("No")
		return
	}

	fmt.Println("Yes")
}
