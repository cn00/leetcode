//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//
//
// 示例 1：
//
//
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
//
//
// 示例 2：
//
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//
//
// 示例 3：
//
//
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
//
//
//
//
// 提示：
//
//
// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零
//
// Related Topics 递归 链表 数学 👍 8327 👎 0

package main

import (
	"fmt"
	"math"
)

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

//leetcode submit region begin(Prohibit modification and deletion)

func (l *ListNode) V() (v int64) {
	var i = l
	var n = 0
	for {
		if i == nil {
			break
		}
		v += int64(i.Val) * int64(math.Pow(10, float64(n)))
		n++
		i = i.Next
	}
	return
}

func NewListNode(v int64) (root *ListNode) {
	var p *ListNode = nil
	for {
		if v == 0 {
			break
		}
		var i = v % 10
		var pi = new(ListNode)
		pi.Val = int(i)
		if p == nil {
			root = pi
		} else {
			p.Next = pi
		}
		p = pi
		v = v / 10
	}

	//p = root
	//for{
	//	if p == nil {break}
	//	fmt.Println(p.Val)
	//	p = p.Next
	//}
	fmt.Println("---", root.V())
	return
}

// x->y->z->
func (l *ListNode) Reverse() (r *ListNode) {
	return Reverse(l)
}

func (l *ListNode) Print() (r *ListNode) {
	var i = l
	for {
		if i == nil {
			break
		}
		fmt.Printf("%v->", i.Val)
		i = i.Next
	}
	fmt.Println("=", l.V())
	return l
}

func Reverse(l *ListNode) (r *ListNode) {
	var p1, p2, p3 = l, l.Next, l.Next
	p1.Next = nil
	for {
		p3 = p3.Next
		p2.Next = p1
		p1 = p2
		p2 = p3
		if p3 == nil {
			break
		}
	}
	r = p1
	return
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) (r *ListNode) {
	var r1, r2 = l1, l2 // Reverse(l1).Print(""), Reverse(l2).Print("")
	var flow = 0
	var p1, p2, p3 *ListNode = r1, r2, nil
	for {
		if p1 == nil && p2 == nil {
			break
		}
		var v = 0
		if p1 != nil {
			v += p1.Val
		}
		if p2 != nil {
			v += p2.Val
		}
		p3 = &ListNode{(v + flow) % 10, r}
		flow = (v + flow) / 10
		r = p3
		fmt.Printf("%v %v %v\n", p1, p2, p3.Val)
		if p1 != nil {
			p1 = p1.Next
		}
		if p2 != nil {
			p2 = p2.Next
		}
	}
	if flow > 0 {
		p3 = &ListNode{flow, r}
		r = p3
	}
	return Reverse(r)
}

//leetcode submit region end(Prohibit modification and deletion)

func main() {
	var l1 = NewListNode(999).Print()
	var l2 = NewListNode(99999).Print()
	addTwoNumbers(l1, l2).Print()

	//NewListNode(12345678).Print().Reverse().Print()
}
