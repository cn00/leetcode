#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/**
给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interval-list-intersections
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes){
    if(firstListSize == 0 || secondListSize == 0){
        *returnSize = 0;
        return 0;
    }

    int* p1 = firstList[0], *p2 = secondList[0];
    int* t1 = p1 + 1, *t2 = p2 + 1;
    int* cl = 0, *cr = 0;
    int** returnList   = malloc((firstListSize+secondListSize)*sizeof(int*));
    *returnColumnSizes = malloc((firstListSize+secondListSize)*sizeof(int));
    int i = 0, j = 0, c = 0;
    while(i < firstListSize && j < secondListSize){
        printf("%d:%d\n", i, j);
        p1 = firstList[i]; p2 = secondList[j];
        t1 = p1 + 1; t2 = p2 + 1;
        /*
        l1:   --  ---- 
        l2:      --- ---
        l2:--  --- 
        */
        if(*t1 < *p2){++i;continue;}
        if(*t2 < *p1){++j;continue;}

        /*
        l1:  ----     ---- ----
        l2:   ----  --- - ---
        l2:   --   ---
        l2: ---   ---
        l2: -------   ---
        l2: ------------   ---
        */
        printf("%d:%d [%d:%d] [%d:%d]\n", i, j, *p1, *t1, *p2, *t2);
        if(*p1 <= *p2 && *t1 <= *t2){cl = p2;cr = t1;++i;}
        else if(*p1 <= *p2 && *t1 >= *t2){cl = p2;cr = t2;++j;}
        else if(*p1 >= *p2 && *t1 >= *t2){cl = p1;cr = t2;++j;}
        else if(*p1 >= *p2 && *t1 <= *t2){cl = p1;cr = t1;++i;}

        printf("%d:%d [%d:%d] [%d:%d]\t->res:[%d,%d]\n", i, j, *p1, *t1, *p2, *t2, *cl, *cr);
        returnList[c] = malloc(2*sizeof(int));
        returnList[c][0] = *cl;
        returnList[c][1] = *cr;
        printf("\t->%d res:[%d,%d]\n",c, *cl, *cr);
        (*returnColumnSizes)[c] = 2;
        ++c;
    }
    *returnSize = c;
    return returnList;
}

int main(int c, char** vv){
    const int col = 2;
    // int s1[][col] = {{1,3},{16,20},{23,30}};
    // int s2[][col] = {{1,7},{10,20},{23,60}};
    // int s1[][col] = {{0,2},{5,10},{13,23},{24,25}};
    // int s2[][col] = {{1,5},{8,12},{15,24},{25,26}};

    int s1[][col] = {{8,15}};
    int s2[][col] = {{2,6},{8,10},{12,20}};

    // int* p1[] = {s1[0],s1[1],s1[2],s1[3]};
    // int* p2[] = {s2[0],s2[1],s2[2],s2[3]};
    int* p1[] = {s1[0]};
    int* p2[] = {s2[0],s2[1],s2[2]};


    // int matrix[][col] = {{1}};
    // int* p[1] = {matrix[0]};
    // int matrix[][col] = {{1},{3}};
    // int* p[2] = {matrix[0],matrix[1]};
    int returnSize = 0;
    int* returnColumnSizes = 0;
    int firstListSize = sizeof(p1)/sizeof(int*);
    int secondListSize =sizeof(p2)/sizeof(int*);
    int firstListColSize = 2;
    int secondListColSize = 2;
    intervalIntersection(p1, firstListSize, &firstListColSize, p2, secondListSize, &secondListColSize, &returnSize, &returnColumnSizes);
    printf("returnSize:%d\n", returnSize);
    return 0;
}