#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
0---     
1----    
2-----   
3------  
4------- <-m=2
5        
6-       
7--      


------  
-       
--      <-m=2
---     
----    
-----   
*/
int roundSearch(int* nums, int i, int j){
    int h = (i+j)/2;

    if(nums[i] <= nums[h] && nums[h] <= nums[j])
        return i;

    printf("rs>i:%d:%d j:%d:%d h:%d:%d\n", i, nums[i],j, nums[j],h, nums[h]);
    if(nums[i] <= nums[h]){
        return roundSearch(nums, h+1, j);
    } else {
        return roundSearch(nums, i, h);
    }
}
int findMin(int* nums, int numsSize){
    int i = roundSearch(nums, 0, numsSize-1);
    return nums[i];
}

int main(int c, char** vv){
    // int nums[] = {4,5,6,7,0,1,2};
    // int nums[] = {5,1,3};
    int nums[] = {3,4,5,6,-7,0,1,2,2,2,2,2};
    int i = findMin(nums, sizeof(nums)/sizeof(int));
    printf("find:%d\n", i);

    return 0;
}