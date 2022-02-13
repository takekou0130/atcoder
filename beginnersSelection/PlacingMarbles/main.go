package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scanf("%s", &a)
	fmt.Println(strings.Count(a, "1"))
}
