//有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的
//字母，只保留第1个，将所得结果作为新字母表开头，并将新建立的字母表中未出现的字母按照正常字母表顺序加入新字母表。如下所示： A B C D E F G H I
//J K L M N O P Q R S T U V W X Y Z T R A I L B Z E S C D F G H J K M N O P Q U V
//W X Y (实际需建立小写字母的字母表，此字母表仅为方便演示） 上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，并
//用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。因此，使用这个密匙， Attack AT DAWN (黎明时攻击)就会被加密为
//Tpptad TP ITVH。 请实现下述接口，通过指定的密匙和明文得到密文。 数据范围： ，保证输入的字符串中仅包含小写字母
// Related Topics 字符串
//示例:
//输入:nihao ni
//输出:le
//

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func MakePwd(s string) []byte {
	var flg = 0x00
	var pw []byte
	for _, v := range []byte(s) {
		if (0x01<<(v-'A'))&flg == 0 {
			pw = append(pw, v)
			flg |= 0x01 << (v - 'A')
		}
	}
	for i := 0; i < 26; i++ {
		if (0x01<<i)&flg == 0 {
			pw = append(pw, byte(i+'A'))
			flg |= 0x01 << i
		}
	}
	return pw
}

func Encode(s, pw []byte) string {
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' {
			s[i] = pw[s[i]-'a'] + 32
		} else {
			s[i] = pw[s[i]-'A']
		}
	}
	return string(s)
}

func main() {
	fmt.Println("字符串加密")
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	pw := MakePwd(strings.ToUpper(sc.Text()))
	sc.Scan()
	fmt.Println(Encode(sc.Bytes(), pw))
}
