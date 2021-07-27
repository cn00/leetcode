#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
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