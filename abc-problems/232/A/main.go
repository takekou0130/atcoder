package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	arr := strings.Split(s, "")
	a, _ := strconv.Atoi(arr[0])
	b, _ := strconv.Atoi(arr[2])
	fmt.Println(a * b)
}
