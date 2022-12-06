/*
题目描述

一张CT扫描的灰度图像可以用一个N*N（0< N< 100）的矩阵描述，矩阵上的每个点对应一个灰度值（整数），其取值范围是0-255。我们假设给定的图像中有且只有一个肿瘤。在图上监测肿瘤的方法如下：如果某个点对应的灰度值小于等于50，则这个点在肿瘤上，否则不在肿瘤上。我们把在肿瘤上的点的数目加起来，就得到了肿瘤在图上的面积。任何在肿瘤上的点，如果它是图像的边界或者它的上下左右四个相邻点中至少有一个是非肿瘤上的点，则该点称为肿瘤的边界点。肿瘤的边界点的个数称为肿瘤的周长。现在给定一个图像，要求计算其中的肿瘤的面积和周长。
关于输入

输入第一行包含一个正整数N (0< N< 100) 表示图像的大小；接下来N行，每行包含图像的一行。图像的一行用N个整数表示（所有整数大于等于0，小于等于255），两个整数之间用一个空格隔开。
关于输出

输出只有一行，该行包含两个正整数，分别为给定图像中肿瘤的面积和周长，用一个空格分开。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main () {
    int side; //边长
    int i,j; 
    int S = 0, C = 0;
    scanf("%d", &side);
    int Square[side][side];
    for (i=0;i<side;i++){
        for (j=0;j<side;j++){
            scanf("%d", &Square[i][j]);
        }
    }

    for (i=0;i<side;i++){
        for (j=0;j<side;j++){
            if (Square[i][j] <= 50){
                S++;
                if (i==side-1 || j==side-1 || i==0 || j==0){
                    C++;
                } //注意，边界点的下标之一不是 side 而是 side - 1 。
                else if (Square[i-1][j] > 50 || 
                Square[i+1][j] > 50 || 
                Square[i][j-1] > 50 || 
                Square[i][j+1] > 50 ){
                    C++;
                }
            }
        }
    } 
    cout << S <<" "<< C << endl;
    return 0;
}