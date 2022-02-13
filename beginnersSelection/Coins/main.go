package main

import "fmt"

func main() {
	var a, b, c, target int
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)
	fmt.Scanf("%d", &c)
	fmt.Scanf("%d", &target)

	var res int

	for numOfA := 0; numOfA <= a; numOfA++ {
		totalA := 500 * numOfA
		if totalA > target {
			continue
		} else if totalA == target {
			res++
			continue
		}

		for numOfB := 0; numOfB <= b; numOfB++ {
			totalB := 100 * numOfB
			if totalA+totalB > target {
				continue
			} else if totalA+totalB == target {
				res++
				continue
			}

			for numOfC := 0; numOfC <= c; numOfC++ {
				totalC := 50 * numOfC
				if totalA+totalB+totalC > target {
					continue
				} else if totalA+totalB+totalC == target {
					res++
					continue
				}
			}
		}

	}

	fmt.Println(res)
}
