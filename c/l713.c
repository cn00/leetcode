
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
给定一个正整数数组 nums和整数 k 。
请找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:
输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if(k <= 1)return 0;
    int c = 0;
    for(int i = 0, l = 0, p = 1;i < numsSize;++i){
        p *= nums[i];
        while(p>=k) p /= nums[l++]; //左边界右移
        c += (i-l+1); // !!! 跨步后若区间不为空,所有子向量都是解
    }
    return c;
}

int main(int c, char** v){
    // int s[] = {10,5,2,6};int k = 100;
    // int s[] = {1,2,3};int k = 0;
    int s[] = {1,1,1};int k = 1;
    // int s[] = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};int k = 19;
    int rs = 0;
    int r = numSubarrayProductLessThanK(s, sizeof(s)/sizeof(int), k);
    printf("r:%d\n", r);

    return 0;
}