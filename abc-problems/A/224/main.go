package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	if strings.HasSuffix(s, "er") {
		fmt.Println("er")
	} else if strings.HasSuffix(s, "ist") {
		fmt.Println("ist")
	}
}
