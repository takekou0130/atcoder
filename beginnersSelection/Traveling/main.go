package main

import (
	"fmt"
)

func main() {
	var n int
	var arr = [][]int{{0, 0, 0}}
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var tmp_arr []int
		var tmp int
		for i := 0; i < 3; i++ {
			fmt.Scanf("%d", &tmp)
			tmp_arr = append(tmp_arr, tmp)
		}
		arr = append(arr, tmp_arr)
	}

	var flag = true
	for idx, current := range arr {
		if idx == 0 {
			continue
		}

		// 動かないといけない回数
		need_move := current[0] - arr[idx-1][0]

		// 最短経路の回数
		min_move := abs(current[1]-arr[idx-1][1]) + abs(current[2]-arr[idx-1][2])

		// 最短で行って2の倍数回暇つぶしすると考える
		// そもそも最短でいけないとき
		if need_move < min_move {
			flag = false
			break
		}

		// 暇つぶしが2の倍数にならないとき
		rest_move := need_move - min_move
		if rest_move%2 == 1 {
			flag = false
			break
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}
