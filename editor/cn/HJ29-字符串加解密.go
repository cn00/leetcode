//对输入的字符串进行加解密，并输出。 加密方法为： 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换
//为a； 当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0； 其他字符不做变化。 解密方法为加密的逆过程。 数据范围：输入的两个字符串长度满足 ，保证
//输入的字符串都是只由大小写字母或者数字组成
//
// Related Topics 字符串 模拟
//示例:
//输入:abcdefg BCDEFGH
//输出:BCDEFGH abcdefg
//

package main

import (
	"bufio"
	"fmt"
	"os"
)

func Encode(s string) string {
	buf := []byte(s)
	for i := 0; i < len(s); i++ {
		if buf[i] >= 'A' && buf[i] < 'Z' {
			buf[i] = buf[i] + 1 + ('a' - 'A')
		} else if buf[i] == 'Z' {
			buf[i] = 'a'
		} else if buf[i] >= 'a' && buf[i] < 'z' {
			buf[i] = buf[i] + 1 - ('a' - 'A')
		} else if buf[i] == 'z' {
			buf[i] = 'A'
		} else if buf[i] >= '0' && buf[i] < '9' {
			buf[i] = buf[i] + 1
		} else if buf[i] == '9' {
			buf[i] = '0'
		}
	}
	return string(buf)
}

func Decode(s string) string {
	buf := []byte(s)
	for i := 0; i < len(s); i++ {
		if buf[i] == 'A' {
			buf[i] = 'z'
		} else if buf[i] > 'A' && buf[i] <= 'Z' {
			buf[i] = buf[i] - 1 + ('a' - 'A')
		} else if buf[i] == 'a' {
			buf[i] = 'Z'
		} else if buf[i] > 'a' && buf[i] <= 'z' {
			buf[i] = buf[i] - 1 - ('a' - 'A')
		} else if buf[i] > '0' && buf[i] <= '9' {
			buf[i] = buf[i] - 1
		} else if buf[i] == '0' {
			buf[i] = '9'
		}
	}
	return string(buf)
}

func main() {
	//fmt.Println("字符串加解密")
	sc := bufio.NewScanner(os.Stdin)
	//sc.Split(bufio.ScanLines)
	sc.Scan()
	s := sc.Text()
	fmt.Println(Encode(s))

	sc.Scan()
	s = sc.Text()
	fmt.Println(Decode(s))
}
