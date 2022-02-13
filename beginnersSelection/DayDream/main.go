package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	if s == "" {
		fmt.Println("NO")
		return
	}

	for {
		var ok bool
		s, ok = checkWord(s)
		if !ok {
			fmt.Println("NO")
			break
		}
		if s == "" {
			fmt.Println("YES")
			break
		}
	}
}

func checkWord(s string) (string, bool) {
	dictionary := []string{"dreamer", "eraser", "dream", "erase"}
	for _, word := range dictionary {
		search_result := strings.LastIndex(s, word)
		if search_result == -1 {
			continue
		}
		if search_result+len(word) == len(s) {
			return s[:search_result], true
		}
	}
	return s, false
}
