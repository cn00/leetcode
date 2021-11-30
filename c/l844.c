#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* 844
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

 
示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

char* del(char* s){
    char* p1 = s, *p2 = s;
    while(*p2 != 0){
        if(*p2 != '#')
            *(p1++) = *p2;
        else {
            if(p1 > s)
                *(p1--) = 0;
            if(p1 == s)*p1 = 0;
        }
        ++p2;
    }
    *(p1) = 0;
    return s;
}

bool backspaceCompare(char * s, char * t){
    printf("%s\n%s\n\n",s, t);
    del(s);del(t);
    printf("%s\n%s\n\n",s, t);
    return strcmp(s,t) == 0;
}

int main(int c, char** vv){
    char s[] = "rjhbpvh";
    char t[] = "rm#jhbpvh";
    printf("%d\n", backspaceCompare(s,t));
    return 0;
}