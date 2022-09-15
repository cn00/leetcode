//密码要求: 1.长度超过8位 2.包括大小写字母.数字.其它符号,以上四种至少三种 3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换
//行）
// 数据范围：输入的字符串长度满足
//
// Related Topics 字符串 数组 模拟
//示例:
//输入:021Abc9000 021Abc9Abc1 021ABC9000 021$bc9000
//输出:OK NG NG OK
//


package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
)

type Password string

func (s Password) Length() bool{
	b := len(s) >= 8
	return b
}

func (s Password) Ascii() bool {
	n := 0
	if b, _ := regexp.MatchString(`[[:upper:]]+`, string(s));b{n++}
	if b, _ := regexp.MatchString(`[[:lower:]]+`, string(s));b{n++}
	if b, _ := regexp.MatchString(`[[:digit:]]+`, string(s));b{n++}
	if b, _ := regexp.MatchString(`[[:punct:]]+`, string(s));b{n++}
	return n >= 3
}

func (s Password) Repeat() bool {
	m:=0
	for i:= 0; i< len(s)-1; i++ {
		for j:= i+1; j < len(s)-1;j++{
			p,q := i,j
			if s[p:p+1] == s[q:q+1] {
				for p < len(s) && q < len(s) && s[p:p+1] == s[q:q+1]{
					p++;q++
				}
			} else {continue}
			if p - i > m {m = p-i}
		}
	}
	return m < 3
}


func main(){
	sc := bufio.NewScanner(os.Stdin)
	for{
		sc.Scan()
		s := Password(sc.Text())
		if s == "" {return}
		b := s.Length() && s.Ascii() && s.Repeat()
		if b {fmt.Println("OK")}else{
			fmt.Println("NG")
		}
	}
}