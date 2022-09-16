//假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？
// 数据范围：输入的小球初始高度满足 ，且保证是一个整数
// Related Topics 模拟 思维
//示例:
//输入:1
//输出:2.875 0.03125
//

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func distance(n, j int) (l, h float64) {
	f := 1.0
	for i := 1; i < j; i++ {
		f += 2.0 / (math.Pow(2.0, float64(i)))
	}
	l = float64(n) * f
	h = float64(n) * 1.0 / 32

	return
}

func main() {
	//fmt.Println("求小球落地5次后所经历的路程和第5次反弹的高度")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	l, h := distance(n, 5)
	fmt.Println(l)
	fmt.Println(h)
}
