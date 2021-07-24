#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

// 3 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(char * s){
    char f[32]; // 256=32*8
    char* h = s;
    char* p = h;
    char c = 0;
    char b = 0;
    int m = 0;
    int n = 0;
    int step = 1;
    // while(*(++p) != *s && *p!=0)++step;
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
            // printf("\n");
        }else{
            // printf("%c:%-3d-%04x\t", c, c, b);
            f[c/8] |= b;
            ++p;
        }
    }
    n = (p-h);
    if(n>m)m=n;
    return m;
}
int main(int c, char** vv){
    char* s = "asdfsdf ";
    printf("%s: %d\n", s, lengthOfLongestSubstring(s));

    return 0;
}