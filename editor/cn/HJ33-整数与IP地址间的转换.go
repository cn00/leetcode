//原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
// 一个长整数。
// 举例：一个ip地址为10.0.3.193
// 每段数字 相对应的二进制数
// 10 00001010
// 0 00000000
// 3 00000011
// 193 11000001 组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，
//即该IP地址转换后的数字就是它了。
// 数据范围：保证输入的是合法的 IP 序列
//
// Related Topics 字符串 模拟
//示例:
//输入:10.0.3.193 167969729
//输出:167773121 10.3.3.193
//

package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func ToBin(s string) (i int) {
	ss := strings.Split(s, ".")
	var ip = [4]int{}
	ip[0], _ = strconv.Atoi(ss[0])
	ip[1], _ = strconv.Atoi(ss[1])
	ip[2], _ = strconv.Atoi(ss[2])
	ip[3], _ = strconv.Atoi(ss[3])
	for _, v := range ip {
		i <<= 8
		i |= v
	}

	return
}
func ToStr(s string) string {
	i, _ := strconv.Atoi(s)
	var ip = [4]byte{}
	for j := 0; j < 4; j++ {
		ip[3-j] = byte((i >> (8 * j)) & 0xff)
	}
	return fmt.Sprintf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3])
}
func main() {
	//fmt.Println("整数与IP地址间的转换")
	//sc := bufio.NewScanner(os.Stdin)
	//sc.Scan()
	//fmt.Println(ToBin(sc.Text()))
	//sc.Scan()
	//fmt.Println(ToStr(sc.Text()))

	buf := [32]byte{0}
	n, _ := os.Stdin.Read(buf[:])
	//ss:=strings.Split(string(buf[:n]),"\n")
	fmt.Println(ToBin(strings.Trim(string(buf[:n]), " \t\r\n")))
	n, _ = os.Stdin.Read(buf[:])
	fmt.Println(ToStr(strings.Trim(string(buf[:n]), " \t\r\n")))

}

//10.0.3.193
//167969729
