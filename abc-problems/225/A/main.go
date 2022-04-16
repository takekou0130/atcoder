package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	arr := strings.Split(s, "")
	result := map[string]bool{}
	for _, v := range arr {
		result[v] = true
	}
	switch len(result) {
	case 1:
		fmt.Println(1)
	case 2:
		fmt.Println(3)
	case 3:
		fmt.Println(6)
	}
}
