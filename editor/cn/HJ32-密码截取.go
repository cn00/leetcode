//Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，ABA，A，123321，但是他们有时会在开始或结束时加入
//一些无关的字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。因为截获的串太长了，而且存在
//多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，他只能向电脑高手求助，你能帮Catcher找出最长的有
//效密码串吗？
// 数据范围：字符串长度满足
//
// Related Topics 字符串 动态规划
//示例:
//输入:ABBA
//输出:4
//

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	s := sc.Text()
	buf := []byte(s)
	m := 0
	for i := 0; i < len(buf) && len(buf)-i > m; i++ {
		p, q := i, i
		for q < len(buf)-1 && buf[p] == buf[q+1] {
			q++
		}
		for p > 0 && q < len(buf)-1 && buf[p-1] == buf[q+1] {
			p--
			q++
		}
		if m < q-p+1 {
			m = q - p + 1
		}
	}
	fmt.Println(m)
}
