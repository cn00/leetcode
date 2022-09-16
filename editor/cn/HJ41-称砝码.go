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

type BitFlag struct {
	buf []byte
}

// NewBitFlag max 512M bit
func NewBitFlag(l uint) BitFlag {
	var flg = BitFlag{make([]byte, l/8+1)}
	return flg
}

func (b *BitFlag) Get(i uint) bool {
	return b.buf[i/8]&(0x1<<i%8) != 0
}

func (b *BitFlag) Set(i uint) {
	b.buf[i/8] |= byte(0x01 << (i % 8))
}
func (b *BitFlag) Count() (c uint) {
	for _, i := range b.buf {
		for j := 0; j < 8; j++ {
			if i&(0x01<<j) > 0 {
				c++
			}
		}
	}
	return
}

func (b *BitFlag) BinStr() (s string) {
	for i := len(b.buf) - 1; i >= 0; i-- {
		s += fmt.Sprintf("%08b ", b.buf[i])
	}
	return
}

func (b *BitFlag) Print(s ...any) {
	fmt.Println(b.BinStr())
}

func main() {
	//fmt.Println("称砝码")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	var w []uint
	for i := 0; i < n; i++ {
		sc.Scan()
		m, _ := strconv.Atoi(sc.Text())
		w = append(w, uint(m))
	}

	sum := uint(0)
	var m []int
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		m = append(m, x)
		sum += w[i] * uint(x)
	}
	//fmt.Println("m", m)

	var w2 []uint
	for i := 0; i < n; i++ {
		for j := 0; j < m[i]; j++ {
			w2 = append(w2, w[i])
		}
	}
	//fmt.Println("w2", w2)
	var dp = make([][]bool, len(w2)+1)
	var dp2 = NewBitFlag(uint(sum + 1))
	//dp2.Print()
	for i := 0; i <= len(w2); i++ {
		dp[i] = make([]bool, uint(sum+1))
		dp[i][0] = true
	}
	for i := 1; i < len(w2)+1; i++ {
		for j := uint(1); j < sum+1; j++ {
			if j >= w2[i-1] {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-w2[i-1]]
			} else {
				dp[i][j] = dp[i-1][j]
			}
			if dp[i][j] {
				dp2.Set(uint(j))
			}

			//fmt.Println(i, j, dp2.BinStr(), ">", dp[i][j])
		}
	}
	fmt.Println(dp2.Count() + 1)
}

func main2() {
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
