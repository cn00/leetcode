#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int binsearch(int* nums, int target, int i, int j){
    if(i < 0 || j < 0 || j < i) return -1;
    int h = (i+j)/2;
    printf("bs>%d:%d:%d\n", i,j,h);
    if(nums[h]==target)return h;
    if(i == j ) return -1;
    if(nums[h] < target)
        return binsearch(nums, target, h+1, j);
    return     binsearch(nums, target, i,   h);
}
int roundSearch(int* nums, int target, int i, int j){
    int h = (i+j)/2;
    printf("rs>%d:%d:%d\n", i,h,j);
    if(i>j) return -1;

    if(nums[h] == target)return h;

    if(nums[i] < nums[h]){
        if(nums[i] <= target && target <= nums[h])
            return binsearch(nums, target, i, h);
        else
            return roundSearch(nums, target, h+1, j);
    } else {
        if(nums[h+1] <= target && target <= nums[j])
            return binsearch(nums, target, h+1, j);
        else 
            return roundSearch(nums, target, i, h);
    }
}

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
int rsearch(int* nums, int numsSize, int target){
    return roundSearch(nums, target, 0, numsSize-1);
}

int main(int c, char** vv){
    // int nums[] = {4,5,6,7,0,1,2};
    // int nums[] = {5,1,3};
    int nums[] = {4,5,6,7,0,1,2};
    printf("find:%d\n", rsearch(nums, sizeof(nums)/sizeof(int), 0));

    return 0;
}