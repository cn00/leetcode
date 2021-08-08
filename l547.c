
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/*
    547. 省份数量
    有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

    省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

    给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
    返回矩阵中 省份 的数量。

    示例 1：

    输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    输出：2
    示例 2：

    输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    输出：3
     

    提示：

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] 为 1 或 0
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/number-of-provinces
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void markOne(int** g, int m, int i, bool* v){
    for(int j = 0; j < m;++j){
        if((!v[j]) && g[i][j]==1){
            v[j] = true;
            printf("%d,",j);
            markOne(g, m, j, v);
        }
    }
    printf("\n");
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    const int m = isConnectedSize;
    bool* v = malloc(m*sizeof(bool));
    memset(v, 0, m*sizeof(bool));
    int c = 0;
    for(int i = 0;i<m;++i){
        if(!v[i]){
            ++c;
            v[i] = true;
            printf(">%d\ti:%d\n", c, i);
            markOne(isConnected, m, i, v);
        }
    }
    free(v);
    return c;
}

#define TEST_4 1
int main(int c, char** v){
    
    #if TEST_1
    const int n = 4;int g[][n] = {
        {1,1,0},
        {1,1,0},
        {0,0,1},
    };
    #endif

    #if TEST_2
    int n = 1;int g[][1] = {{1}};
    #endif

    #if TEST_3
    int n = 5;int g[][n] = {
        {1,1,0,1,1},
        {1,1,0,1,1},
        {0,0,1,1,0},
        {1,1,1,1,0},
        {1,1,0,0,1},
    };
    #endif

    #if TEST_4
    const int n = 4;int g[][n] = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1}
    };
    #endif

    int m = sizeof(g)/sizeof(g[0]);
    int* p[m];
    for(int i = 0; i < m; ++i)p[i] = &g[i];

    int r = findCircleNum(p, m, &n);
    printf("r:%d\n", r);

    return 0;
}