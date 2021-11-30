#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* 82
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void printList(ListNode* root){
    for(ListNode* p = root; p->next != 0; p=p->next){
        printf("%d\t", p->val);
    }
    printf("\n");
}

ListNode* deleteDuplicates(ListNode* head){
    if(head==0)return 0;

    ListNode* p = head, *nh = head, *dh = head;
    while(p!=0 && p->next != 0){
        p=p->next;
        while(p->next != 0 && p->val == p->next->val)
            p = p->next;
        if(dh->next != p||dh->val==p->val){
            dh->next = p->next; // delete
            if(dh==nh && dh->val==p->val){
                nh=p->next;
                p = dh = nh;
            }
        }else{//step
            dh=p;
        }
    }
    return nh;
}

 ListNode* create(int* nums, int numSize){
    ListNode* r = (ListNode*)malloc(numSize*sizeof(struct ListNode)), 
    *p = r;
    for(int i = 0; i < numSize; ++i){
        p->val = nums[i];
        p->next = p+1;
        printf("%d:%p->%p\n", p->val, p, p->next);
        p = p + 1;
    }
    p->next = 0;
    return r;
}

int main(int c, char** vv){
    const int col = 4;
    int nums[] = {1,2,3,3,4,4,5};
    ListNode* p = create(nums, sizeof(nums)/sizeof(int));
    printList(p);
    ListNode* p2 = deleteDuplicates(p);
    printList(p2);
    return 0;
}