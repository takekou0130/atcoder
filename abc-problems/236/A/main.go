package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	var a, b int
	fmt.Scanf("%s", &s)
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)

	arr := strings.Split(s, "")
	tmp := arr[a-1]
	arr[a-1] = arr[b-1]
	arr[b-1] = tmp
	fmt.Println(strings.Join(arr, ""))
}
