//////开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最
//终输 //入结 //果输出到输出文件里面。 输入： 合法坐标为A(或者D或者W或者S) + 数字（两位以内） 坐标之间以;分隔。 非法坐标点需要进行丢弃。如
//AA10; //A1A; $ //%$; YAD; 等。 下面是一个简单的例子 如： A10;S20;W10;D30;X;A1A;B10A11;;A10; 处理过程
//： 起点（0, //0） + A10 // = （-10,0） + S20 = (-10,-20) + W10 = (-10,-10) + D30 = (20,
//-10) + x = // 无效 + A1A = // 无效 + B10A11 = 无效 + 一个空 不影响 + A10 = (10,-10) 结果 （10， 
//-10） // 数据范围： //每组输入的字符串长度满足 ，坐标保证满足 ，且数字部分仅含正数 // Related Topics 字符串 //示例: //输入
//:A10;S20;W10;D30 //;X;A1A;B10A11;;A10; //输出:10,-10 //


package main

import(
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	x, y int
}

func (n *Node) A(d int) *Node{
	n.x -= d
	return n
}

func (n *Node) S(d int) *Node{
	n.y -= d
	return n
}

func (n *Node) W(d int) *Node{
	n.y += d
	return n
}
func (n *Node) D(d int) *Node{
	n.x += d
	return n
}

func main() {
	buf := [10000]byte{}
	n, _ := os.Stdin.Read(buf[:])
	s := string(buf[:n])
	ss := strings.Split(s, ";")
	node := Node{0,0}
	for _, i := range ss {
		if len(i) < 2{
			continue
		}
		c := i[0:1]
		d,err := strconv.Atoi(i[1:])
		if err != nil {
			continue
		}
		switch c {
		case "A": node.A(d);break;
		case "S": node.S(d);break;
		case "D": node.D(d);break;
		case "W": node.W(d);break;
		}
	}
	fmt.Printf("%d,%d", node.x, node.y)
}