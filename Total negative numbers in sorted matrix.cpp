//You are given an ‘N’ x ‘M’ matrix ‘MAT’, which is sorted in non-increasing order both row-wise and column-wise. Your task is to count the number of negative numbers in ‘MAT’.

For Example:

You are given ‘N’ = 3, ‘M’ = 2 and ‘MAT’= [[3, 1],[2, -1],[1, 2]]. Then the answer will be two for the first test case because there are two negative numbers in the given matrix(-1, -2).
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5000
1 <= M <= 5000
-10^6 <= MAT[i][j] <= 10^6

Time Limit: 1 sec
Sample Input 1:
2
3 2
3 1 
2 -1
1 -2
3 3
3 2 1
0 -1 -2
-3 -4 -5
Sample Output 1:
2
5
Explanation of Sample Input 1:
For the first test case, the answer will be two for the first test case because there are two negative numbers in the given matrix(-1, -2).
For the second test case, the answer will be five because there are five negative numbers in the given matrix(-1, -2, -3, -4, -5).
Sample Input 2:
2
2 2
3 -1 
2 -1
2 2
1 1 
1 1
Sample Output 2:
2
0




#include <bits/stdc++.h> 
int countNegativeNumbers(vector<vector<int>> &mat)
{
   int N = mat.size();
    int M = mat[0].size();
    int count = 0;
    
    int row = 0;
    int col = M - 1;  // Start from the top-right corner

    while (row < N && col >= 0) {
        if (mat[row][col] < 0) {
            // All elements to the left of (row, col) in this row are also negative
            count += (col + 1);  // Count all elements from column 0 to col in this row
            row++;  // Move down to the next row
        } else {
            col--;  // Move left to the next column
        }
    }
    
    return count;
}
