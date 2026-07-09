/* Problem: You are given a rectangular matrix of integers. Starting from the outer boundary,
traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse,
and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/

#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d", &m,&n);

    int matrix[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

        //00 01 02 03
        //10 11 12 13
        //20 21 22 23

        int top=0;
        int right=n-1;//3
        int left=0;
        int bottom=m-1;//2
        int arr[9];
        int count=0;

        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                arr[count]=matrix[top][i];
                count++;
            }top++;

            for(int i=top; i<=bottom; i++){
                arr[count]=matrix[i][right];
                count++;
            }right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--){
                    arr[count]=matrix[bottom][j];
                    count++;}
                    bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--){
                    arr[count]=matrix[i][left];
                    count++;}
                    left++;
            }
        }
    for(int i=0; i<count; i++){
            printf("%d ", arr[i]);
    }
    return 0;
}