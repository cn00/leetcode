
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，root.val = min(root.left.val, root.right.val) 总成立。

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

#define and &&
#define or  ||
int findSecondMinimumValue(struct TreeNode* root){
    struct TreeNode* p = root, *t = root;
    while(p->left != 0){
        if(p->val >= p->left->val){
            if(p->val > p->left->val)
                t = p;
            p = p->left;
        }
    }
    return t->val > p->val  
        ? t->val 
        : t->right != 0 and t->right->val > t->val 
            ? t->right->val 
            : -1;
}

struct TreeNode* create(int* nums, int numsSize){
    struct TreeNode* r = (struct TreeNode*)malloc(numsSize*sizeof(struct TreeNode));
    struct TreeNode* p = 0, *n = 0;
    for(int i = 0; i < numsSize; ++i){
        p = r;
        n = r+i;
        n->val = nums[i];
        n->left = 0;
        n->right = 0;
        if(p == n)continue;
        while(1){
            if(p->val >= n->val){
                if(p->left != 0)
                    p = p->left;
                else {
                    p->left = n;
                    break;
                }
            }else{
                if(p->right != 0)
                    p = p->right;
                else{
                    p->right = n;
                    break;
                }
            }
        }
    }
    return r;
}

void printT(struct TreeNode* t, int numsSize){
    struct TreeNode* p = 0;
    int l = 0,r = 0, v = 0;
    for(int i = 0; i < numsSize;++i){
        p = t + i;
        v = p->val;
        l = p->left != 0 ? p->left->val : 0;
        r = p->right !=0 ? p->right->val: 0;
        printf("%-14p:%d<-%d:%p->%d:%14p\n", p->left, l, v, p, r, p->right);
    }

}

int main(int n, char** v){
    int nums[] = {2,2,2};
    struct TreeNode* root = create(nums, sizeof(nums)/sizeof(int));
    printT(root, sizeof(nums)/sizeof(int));
    printf("%d\n", findSecondMinimumValue(root));
    return 0;
}