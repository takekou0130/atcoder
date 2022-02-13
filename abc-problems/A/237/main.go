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

	min := -1 * math.Pow(2, 31)
	max := 1 * math.Pow(2, 31)
	if min <= n && n < max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
