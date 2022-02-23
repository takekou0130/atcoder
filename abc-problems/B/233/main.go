package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func nextStr() string {
	sc.Scan()
	str := sc.Text()
	return str
}

func main() {
	var l, r int
	var s string
	fmt.Scan(&l, &r, &s)
	fmt.Print(s[0 : l-1])
	for i := r - 1; i >= l-1; i-- {
		fmt.Print(string(s[i]))
	}
	fmt.Println(s[r:])
}
