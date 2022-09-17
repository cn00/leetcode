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

func (f *BitFlag) Get(i uint) (b bool) {
	b = f.buf[i/8]&(0x1<<(i%8)) != 0
	return
}

func (f *BitFlag) Set(i uint) {
	f.buf[i/8] |= byte(0x01 << (i % 8))
}
func (f *BitFlag) Unset(i uint) {
	f.buf[i/8] &= byte((0x01 << (i % 8)) ^ 0xff)
}
func (f *BitFlag) Count() (c uint) {
	for _, i := range f.buf {
		for j := 0; j < 8; j++ {
			if i&(0x01<<j) > 0 {
				c++
			}
		}
	}
	return
}

func (f *BitFlag) BinStr() (s string) {
	for i := len(f.buf) - 1; i >= 0; i-- {
		s += fmt.Sprintf("%08b ", f.buf[i])
	}
	return
}

func (f *BitFlag) Print() {
	fmt.Println(f.BinStr())
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
	var dp = NewBitFlag(sum + 1)
	//dp.Print()

	dp.Set(0)
	sum2 := uint(0)
	for i := uint(0); i < uint(len(w2)); i++ {
		sum2 += w2[i]
		for j := sum2; j > w2[i]; j-- {
			if dp.Get(j - w2[i]) {
				dp.Set(j)
				//fmt.Println(i,j, w2[i],":",dp.BinStr())
			}
		}
		dp.Set(w2[i])
		//fmt.Println(i,w2[i],":",dp.BinStr())
	}
	//fmt.Println(dp.BinStr())
	fmt.Println(dp.Count())
}
