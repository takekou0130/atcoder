package main

import "fmt"

func main() {
	var count, target int
	fmt.Scanf("%d", &count)
	fmt.Scanf("%d", &target)

	var result = []int{-1, -1, -1}
Loop:
	for ichiman := 0; ichiman <= count; ichiman++ {
		for gosen := 0; gosen <= count-ichiman; gosen++ {
			sen := count - ichiman - gosen
			sum := ichiman*10000 + gosen*5000 + sen*1000
			if sum == target {
				result = []int{ichiman, gosen, sen}
				break Loop
			}
		}
	}

	fmt.Printf("%d %d %d\n", result[0], result[1], result[2])
}
