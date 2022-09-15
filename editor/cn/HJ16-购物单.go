package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type RawItem struct {
	V, W, Pid int
	C1, C2 int
}

func max(a, b int) int {
	if a > b {return a} else{return b}
}
func ReadInput() (int, []RawItem) {
	//fmt.Println("购物单")
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanLines)
	sc.Scan()
	nm := strings.Split(sc.Text(), " ")
	n, _ := strconv.Atoi(nm[0])
	m, _ := strconv.Atoi(nm[1])
	var rawItem = make([]RawItem, m)
	for i := 0; i < m; i++ {
		it := &rawItem[i]
		it.C1, it.C2 = -1,-1
	}
	for i := 0; i < m; i++ {
		sc.Scan()
		if sc.Text() == "" {
			break
		}
		vpq := strings.Split(sc.Text(), " ")
		v, _ := strconv.Atoi(vpq[0])
		p, _ := strconv.Atoi(vpq[1])
		q, _ := strconv.Atoi(vpq[2])
		//AddItem(v,p,q)

		it := &rawItem[i]
		//rawItem[i] = RawItem{i, v, v*p, q, 0,0}
		it.V, it.W, it.Pid = v/10, v*p/10, q
		if q != 0 {
			itq := &rawItem[q-1]
			if itq.C1 == -1 {
				itq.C1 = i
			}else{
				itq.C2 = i
			}
		}

	}
	return n/10, rawItem
}

func main(){
	n, goods := ReadInput()
	dp := make([]int, n+1)
	for i := 0; i<len(goods); i++ {
		for j := n; j>=0; j-- {
			if goods[i].Pid != 0 {continue}
			if j >= goods[i].V {
				dp[j] = max(dp[j], dp[j-goods[i].V]+goods[i].W)
			}
			// A+A1
			if goods[i].C1 != -1 && j>= goods[i].V+goods[goods[i].C1].V {
				//
				dp[j] = max(dp[j], dp[j-goods[i].V-goods[goods[i].C1].V]+goods[i].W + goods[goods[i].C1].W)
			}
			// A+A2
			if goods[i].C2 != -1 && j>= goods[i].V+goods[goods[i].C2].V{
				dp[j] = max(dp[j], dp[j-goods[i].V-goods[goods[i].C2].V]+goods[i].W + goods[goods[i].C2].W)
			}
			// A+A1+A2
			if goods[i].C1 != -1 && goods[i].C2 != -1 &&
				j >= goods[i].V + goods[goods[i].C1].V + goods[goods[i].C2].V {
				dp[j] = max(dp[j], dp[j-goods[i].V - goods[goods[i].C1].V - goods[goods[i].C2].V] +
					goods[i].W + goods[goods[i].C1].W + goods[goods[i].C2].W)
			}
			//fmt.Println(i, j, dp)
		}
	}
	//fmt.Println(goods)
	fmt.Println(dp[n]*10)
}