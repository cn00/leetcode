
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 https://leetcode-cn.com/problems/minimum-size-subarray-sum/
*/

int minSubArrayLen(int target, int* nums, int numsSize){
    int k = target;
    if(k <= 1)return 0;
    int c = -1;
    for(int i = 0, l = 0, p = 0;i < numsSize;++i){
        p += nums[i];
        while(p>=k){
            c = (c > i-l+1) ? i-l+1 : c;
            p -= nums[l++]; //左边界右移
            printf("%d\t%d\t%d\t->%d\n", i,l,p,c);
        }
    }
    return c > 0 ? c : 0;
}

int main(int c, char** v){
    // int s[] = {10,5,2,6};int k = 100;
    // int s[] = {1,2,3};int k = 0;
    // int s[] = {1,1,1};int k = 1;
    int s[] = {1,2,1,4,3,8,3,3,6,2,1,10,1,3};int k = 19;
    int rs = 0;
    int r = minSubArrayLen(k, s, sizeof(s)/sizeof(int));
    printf("r:%d\n", r);

    return 0;
}