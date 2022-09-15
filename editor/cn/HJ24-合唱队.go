//N 位同学站成一排，音乐老师要请最少的同学出列，使得剩下的 K 位同学排成合唱队形。 设位同学从左到右依次编号为 1，2…，K ，他们的身高分别为 ，若存在
// 使得 且 ，则称这名同学排成了合唱队形。 通俗来说，能找到一个同学，他的两边的同学身高都依次严格降低的队形就是合唱队形。 例子： 123 124 125 12
//3 121 是一个合唱队形 123 123 124 122不是合唱队形，因为前两名同学身高相等，不符合要求 123 122 121 122不是合唱队形，因为找不
//到一个同学，他的两侧同学身高递减。 
// 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。 
// 注意：不允许改变队列元素的先后顺序 且 不要求最高同学左右人数必须相等 
// 数据范围： 
//
// 
// Related Topics 动态规划 队列 
//示例:
//输入:8 186 186 150 200 160 130 197 200 
//输出:4 
//


package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func ReadInput() (int, []uint16){
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N,_ := strconv.Atoi(sc.Text())
	var l []uint16
	for i := 0;i<N;i++{
		sc.Scan()
		h,_ := strconv.Atoi(sc.Text())
		l = append(l, uint16(h))
	}
	return (N), l
}

func max(a,b int) int {
	if a>b {return a}else{return b}
}

func main(){
	//fmt.Println("合唱队")
	N, l := ReadInput()
	var dpl, dpr  = make([]int, N), make([]int, N)

	// left dp
	for  i :=0;i<N;i++{
		dpl[i] = 1
		for j:=0;j<i;j++{
			if l[i] > l[j] {
				dpl[i] = max(dpl[j]+1, dpl[i])
				//dpl[i] = dpl[j]+1
			}
		}
	}

	// right dp
	for i:=N-1;i>-1;i--{
		dpr[i] = 1
		for j:=N-1;j>i;j--{
			if l[i] > l[j] {
				dpr[i] = max(dpr[j]+1, dpr[i])
				//dpr[i] = dpr[j]+1
			}
		}
	}

	var m int = 1
	for i := 0;i < N; i++{
		si := dpl[i]+dpr[i]-1
		if si > m { m = si }
	}
	//fmt.Println(dpl)
	//fmt.Println(dpr)
	fmt.Println(N-int(m))
}