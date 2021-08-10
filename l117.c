
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
117. 填充每个节点的下一个右侧节点指针 II
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

示例：

输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。

提示：
树中的节点数小于 6000
-100 <= node.val <= 100
*/


typedef struct{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
} Node;

/*
   |                   |  
   a                   c            
  / \                 / \            
 b   c               a   e          
    / \             / \               
   d   e           b   d                 
*/          
Node* rleft(Node*p){

}

Node* rright(Node*p){

}

struct Node* connect(struct Node* root) {
    Node* h = root, *nh=0, *i = 0, *p = 0;
    while(h!= 0){
        nh = 0;
        for(p=h,i=0;p!=0;p=p->next){
            if(p->left != 0){
                if(i)i->next = p->left;
                if(nh==0)nh=p->left;
                i = p->left;//i=i->next
            }
            if(p->right!=0){
                if(i)i->next = p->right;
                if(nh==0)nh=p->right;
                i = p->right;//i=i->next
            }
        }
        h = nh;
    }
    return root;
}

int main(int n, char** v){
    int nums[] = {1,2,3,1};
    printf("%d\n", findPeakElement(nums, sizeof(nums)/sizeof(int)));
}