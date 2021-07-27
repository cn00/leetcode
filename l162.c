
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
峰值元素是指其值大于左右相邻值的元素。

给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int findPeakElement(int* nums, int numsSize){
    int maxh = 0;
    for (int i = 1; i < numsSize; ++i){
        if( nums[maxh] <= nums[i])maxh = i;
        else return maxh;
    }
    return maxh;
}

int main(int n, char** v){
    int nums[] = {1,2,3,1};
    printf("%d\n", findPeakElement(nums, sizeof(nums)/sizeof(int)));
}