//计算一个浮点数的立方根，不使用库函数。 保留一位小数。
//
// 数据范围：
// Related Topics 基础数学 二分
//示例:
//输入:19.9
//输出:2.7
//

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n))
func cubeRoot(n, d float64) float64 {
	x := 1.0
	x1 := x - (x*x*x-n)/(3*x*x)
	for x-x1 > d || x-x1 < -d {
		x = x1
		x1 = x - (x*x*x-n)/(3*x*x)
	}
	return x1
}

func cubeRoot2(n, d float64) float64 {
	nn := math.Abs(n)
	x1, x2 := 0., nn
	if x2 < 1.0 {
		x2 = 1.0
	}
	x := (x1 + x2) / 2
	xxx := x * x * x
	dd := math.Abs(x*x*x - nn)
	for dd > d {
		xxx = x * x * x
		if xxx > nn {
			x2 = (x1 + x2) / 2
		} else if xxx < nn {
			x1 = (x1 + x2) / 2
		}
		x = (x1 + x2) / 2
		dd = math.Abs(x*x*x - nn)
		fmt.Println(n, x1, x, x2, dd, xxx)
	}
	return x
}

func main() {
	//fmt.Println("求解立方根")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.ParseFloat(sc.Text(), 10)
	fmt.Printf("%.1f", cubeRoot2(n, 0.01))
}
