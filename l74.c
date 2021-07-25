#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/* 74 https://leetcode-cn.com/problems/search-a-2d-matrix/
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
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

int binsearchV(int** matrix, int i1, int i2, int colSize, int target){
    if(i1 < 0 || i2 < 0 || i2 < i1) return -1;

    int m = (i1 + i2)/2;
    printf("vs>%d:%d:%d\n", i1,i2,m);
    if((matrix[m][0]<=target && target <= matrix[m][colSize-1]) 
        || i1==i2)// 端点
        return binsearch(matrix[m], target, 0, colSize-1);
    
    if(target<matrix[m][0]){
        return binsearchV(matrix, i1,  m,  colSize, target);
    }

    if(matrix[m][colSize-1]<target)
        return binsearchV(matrix, m+1, i2, colSize, target);
    return -1;
}

bool searchMatrix(int** matrix, int matrixSize, const int* matrixColSize, int target){
    int i = binsearchV(matrix, 0, matrixSize-1, *matrixColSize, target);

    // // only ok on macosx
    // int* p =matrix[0];
    // int i = binsearch(p, target, 0, matrixSize * (*matrixColSize) - 1);

    printf("%d\n", i);
    return i >= 0?true:false;
}


int main(int c, char** vv){
    const int col = 4;
    int matrix[][col] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int* p[3] = {matrix[0],matrix[1],matrix[3]};
    // int matrix[][col] = {{1}};
    // int* p[1] = {matrix[0]};
    // int matrix[][col] = {{1},{3}};
    // int* p[2] = {matrix[0],matrix[1]};
    printf("%d\n", searchMatrix(p, sizeof(matrix)/sizeof(matrix[0]), &col, 3));
    // printf("b:%d\n", binsearch(p[0], 3, 0, sizeof(matrix)/sizeof(int)-1));
    return 0;
}