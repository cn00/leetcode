#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

// https://leetcode-cn.com/problems/median-of-two-sorted-arrays
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

int lengthOfLongestSubstring(char * s){
    char f[32]; // 256=32*8
    char* h = s;
    char c = 0;
    char b = 0;
    int m = 0;
    int n = 0;
    int step = 1;
    char* p = h;

    // while(*p!=0){if (*p == *s)break;++step;++p;}
    // printf("step:%d\n", step);
    
    memset((void*)f, 0, 32);
    p = s;
    while(*p != 0){
        c = *p;
        b = 0x1 << (int)(c%8);
        if(f[c/8]&b){
            h += step;
            n = (p-h) + 1;
            if(n>m)m=n;
            p = h;
            memset((void*)f, 0, 32);
            printf("nm:%d/%d\n", n,m);
        }else{
            printf("%c:%04x\t", c, b);
            f[c/8] |= b;
            ++p;
        }
    }
    n = (p-h);
    if(n>m)m=n;
    return m;
}

int main(int c, char** vv){
    // 1,2,2,3,3,4,5
    int ns1[] = {1,3};
    int ns2[] = {2,7};
    int l1 = sizeof(ns1)/sizeof(int);
    int l2 = sizeof(ns2)/sizeof(int);
    // printf("%f\n", findMedianSortedArrays(ns1, l1, ns2, l2));


    char* s = "asdfsdf ";
    printf("%s: %d\n", s, lengthOfLongestSubstring(s));
    return 0;
}