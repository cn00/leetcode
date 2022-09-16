//现有n种砝码，重量互不相等，分别为 m1,m2,m3…mn ；
// 每种砝码对应的数量为 x1,x2,x3...xn 。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。 注： 称重重量包括 0
// 数据范围：每组输入数据满足 ， ，
//
// Related Topics 字符串 哈希
//示例:
//输入:2 1 2 2 1
//输出:5
//

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main1() {
	fmt.Println("称砝码")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	w := []int{}
	for i := 0; i < n; i++ {
		sc.Scan()
		m, _ := strconv.Atoi(sc.Text())
		w = append(w, m)
	}

	sum := 0
	m := []int{}
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		m = append(m, x)
		sum += w[i] * x
	}
	fmt.Println("m", m)

	var w2 = []int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m[i]; j++ {
			w2 = append(w2, w[i])
		}
	}
	fmt.Println("w2", w2)
	var dp = make([]bool, sum+1)
	dp[0] = true
	for i := 0; i < len(w2); i++ {
		//dp[w2[i]] = w2[i]
		//fmt.Println(i, dp)
		for j := 1; j < sum+1; j++ {
			if j >= w2[i] {
				dp[j] = dp[j] || dp[j-w2[i]]
			}

			fmt.Println(i, j, dp)
		}
	}
	c := 0
	for _, v := range dp {
		if v {
			c++
		}
	}
	fmt.Println(c)
}

func main() {
	fmt.Println("称砝码")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	w := []int{}
	for i := 0; i < n; i++ {
		sc.Scan()
		m, _ := strconv.Atoi(sc.Text())
		w = append(w, m)
	}

	sum := 0
	m := []int{}
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		m = append(m, x)
		sum += w[i] * x
	}
	fmt.Println("m", m)

	var w2 = []int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m[i]; j++ {
			w2 = append(w2, w[i])
		}
	}
	fmt.Println("w2", w2)
	var dp = make([]int, sum+1)
	//dp[0] = 1
	for i := 0; i < len(w2); i++ {
		dp[w2[i]] = w2[i]
		fmt.Println(i, dp)
		for j := 1; j < sum+1; j++ {
			if j >= w2[i] {
				dp[j] = max(dp[j], dp[j-w2[i]]+w2[i])
			}

			fmt.Println(i, j, dp)
		}
	}
	c := 0
	for j, v := range dp {
		if v == j {
			c++
		}
	}
	fmt.Println(c)
}
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
