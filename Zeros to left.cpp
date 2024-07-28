//You are given an array 'ARR' of integers. Your task is to modify the array so that all the array elements having zero values get pushed to the left and all the array elements having non-zero value come after them while maintaining their relative order.

For example :
Consider the array { 1, 1, 0, 2, 0 }. 
For the given array the modified array should be {0,0,1,1,2} . 
Arrays { 0, 0, 1, 2, 1 } and  { 0, 0, 2, 1, 1 } are not the correctly reorganized array even if they have all the zero values pushed to the left as in both the arrays the relative order of non-zero elements is not maintained.
Follow Up :
Can you solve the problem in linear time, and constant space?
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^5
-10^9 <= ARR[i] <= 10^9

Where 'T' denotes the number of test cases, 'N' denotes the number of elements in the array ‘ARR’ respectively, and 'ARR[i]' denotes the ’i-th’ element of the array 'ARR'. 

Time limit: 1 second
Sample Input 1 :
2 
5
1 2 0 0 1
3
1 0 0
Sample Output 1 :
0 0 1 2 1
0 0 1
Explanation for sample input 1 :
For the first test case, the given array is { 1, 2, 0, 0, 1 }, if we move all the zeros to the left the modified array becomes { 0, 0, 1, 2, 1} which is our final answer. 

For the second test case, the given array is { 1, 0, 0}, if we move all the zeros to the left the modified array becomes { 0, 0, 1} which is our final answer.
Sample Input 2 :
1
5
1 2 3 4 5
Sample Output 2 :
1 2 3 4 5


#include <iostream>
#include <vector>
using namespace std;

void moveZerosToLeft(vector<int> &arr, int n) {
    int zeroPos = 0;

    for (int current = 0; current < n; ++current) {
        if (arr[current] != 0) {
            swap(arr[zeroPos], arr[current]);
            ++zeroPos;
        }
    }
}
