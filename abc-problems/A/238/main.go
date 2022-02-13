package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n float64
	fmt.Fscan(r, &n)
	left := math.Pow(2, n)
	right := math.Pow(n, 2)
	if left > right {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
