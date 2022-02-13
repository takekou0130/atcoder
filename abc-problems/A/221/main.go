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

	var a, b float64
	fmt.Fscan(r, &a)
	fmt.Fscan(r, &b)
	i := a - b
	fmt.Println(int(math.Pow(32, i)))
}
