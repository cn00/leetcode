#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int binsearch(int* nums, int target, int i, int j);
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* s = malloc(2*sizeof(int));
    memset(s, -1, 2*sizeof(int));
    int i = binsearch(nums, target, 0, numsSize-1);
    *returnSize = 2;
    if(i < 0){return s;}
    int b = i, e = i;
    while(b>=0 && nums[b]==target)--b;s[0] = b+1;
    while(e<numsSize && nums[e]==target)++e;s[1] = e-1;
    // *returnSize = s[1]-s[0]+1;
    printf("i:%d [%d,%d] returnSize:%d\n",i, s[0], s[1], *returnSize);
    return s;
}

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

int main(int c, char** vv){
    int ns[] = {7,8,8,10};
    int rs = 0;
    int* sz = searchRange(ns, sizeof(ns)/sizeof(int), 8, &rs);
    printf("%d, %d\n", sz[0], sz[1]);
    free(sz);
    return 0;
}