#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

// 4 https://leetcode-cn.com/problems/median-of-two-sorted-arrays
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
double getKthArrays(int* nums1, int l1, int* nums2, int l2, int k){
    int i1 = 0;
    int i2 = 0;
    int h = 0;
    int ni1 = 0;
    int ni2 = 0;
    int p1 = 0;
    int p2 = 0;
    while(1){
        if(i1 == l1) return nums2[i2+k-1];
        if(i2 == l2) return nums1[i1+k-1];
        if(k == 1)   return MIN(nums1[i1], nums2[i2]);

        h = k/2;
        ni1 = MIN(i1 + h, l1) - 1;
        ni2 = MIN(i2 + h, l2) - 1;
        p1 = nums1[ni1];
        p2 = nums2[ni2];
        if(p1 <= p2){
            k -= (ni1 - i1 + 1);
            i1 = ni1 + 1;
        }else{
            k -= (ni2 - i2 + 1);
            i2 = ni2 + 1;
        }
    }
    return 0;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int s = nums1Size + nums2Size;
    if(s%2 == 1){
        return getKthArrays(nums1, nums1Size, nums2, nums2Size, s/2 + 1);
    }
    else return   getKthArrays(nums1, nums1Size, nums2, nums2Size, s/2  )/2.0f 
                + getKthArrays(nums1, nums1Size, nums2, nums2Size, s/2+1)/2.0f;
}

int main(int c, char** vv){
    int ns1[] = {1,3};
    int ns2[] = {2,7};
    int l1 = sizeof(ns1)/sizeof(int);
    int l2 = sizeof(ns2)/sizeof(int);
    printf("%f\n", findMedianSortedArrays(ns1, l1, ns2, l2));
    return 0;
}