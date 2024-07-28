Ninja Land can be represented as a N * N grid in the XY plane. Each cell of this grid can have a building of some height.

You are given a matrix ‘GRID[][]’ of size ‘N’ * ‘N’, where ‘GRID[i][j]’ gives the height of the building at cell (i, j) in XY plane. Note, building at any cell (i, j) is represented as a cuboid that is an axis aligned with the axis ‘X’, ‘Y’, ‘Z’ and has the dimension 1 * 1 * GRID[i][j] along X, Y, Z-axis respectively.

Ninja views the projection of these buildings onto the XY, YZ, and ZX planes. A projection is like a shadow, that maps a 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking from the top, the side, and the front, in XY, YZ, ZX plane respectively.

Your task is to find and return the total area of all three projections. See the example for more clarity.

Note:
 ‘GRID[i][j]’ = 0, if there is no building at cell (i, j).
Example:
Consider the following 2*2 ‘GRID[][]’:
                [1, 2]
                [3, 4]

Its projection in XY, YZ, XZ plane is shown below -: 

Area covered in XY plane is 4, Area covered in YZ plane is 6, Area covered in ZX plane is 7, Thus the total area is 4 + 6 + 7 = 17.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
2 <= N <= 1000
0 <= GRID[i][j] <= 100

Where ‘GRID[i][j]’ is the height of the building at cell (i, j).

Time limit: 1 sec
Sample Input 1:
2
1
1
2
1 2
3 4
Sample Output 1:
3
17
Explanation of sample input 1:
In the first test case,  there is a 1*1 grid, and its only cell i.e cell (0, 0) has a building of height 1. Thus its projection in all three planes also takes area 1.

For the second test case, see the problem statement for an explanation. 
Sample Input 2:
2
3
0 0 0
0 0 0
0 0 0
3
1 1 1
1 0 1
1 1 1
Sample Output 2:
0
14


#include <bits/stdc++.h> 
int projectionArea(vector<vector<int>> &grid) {
     int N = grid.size();
    int xyArea = 0;
    int yzArea = 0;
    int zxArea = 0;
    
    // Calculate XY projection area
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] > 0) {
                xyArea++;
            }
        }
    }
    
    // Calculate YZ projection area
    for (int i = 0; i < N; ++i) {
        int maxRow = 0;
        for (int j = 0; j < N; ++j) {
            maxRow = max(maxRow, grid[i][j]);
        }
        yzArea += maxRow;
    }
    
    // Calculate ZX projection area
    for (int j = 0; j < N; ++j) {
        int maxCol = 0;
        for (int i = 0; i < N; ++i) {
            maxCol = max(maxCol, grid[i][j]);
        }
        zxArea += maxCol;
    }
    
    return xyArea + yzArea + zxArea;
}
