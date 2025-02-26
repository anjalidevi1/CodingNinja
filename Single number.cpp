//You are given an array A of length N, where N is always an odd integer. There are (N-1)/2 elements in the array that occur twice and one element which occurs once.

Your task is to find the only element that occurs once in the array.

Note: There are (N-1)/2+1 elements that are unique in the array.

Example:
Consider the array be 1,6,4,6,2,4,2
The integers 2, 4, 6 occur twice and only the integer 1 occurs once. 
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
7 3 5 4 5 3 4
Sample Output 1:
7
Explanation For Sample Input 1:
The integers 3, 4, 5 occur twice and only the integer 7 occurs once.
Sample Input 2:
9
5 6 9 6 1 9 1 5 3
Sample Output 2:
3
Explanation For Sample Input 2:
The integers 1, 5, 6, 9 occur twice and only the integer 3 occurs once.
Expected Time Complexity:
O(N), where ‘N’ is the length of the given array
Constraints:
1 <= N <= 10^4
-10^6 <=  A[i] <=10^6

Where T denotes the number of test cases and N denotes the length of array A[].

Time Limit: 1 sec



#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n){
	int uniqueElement = 0;
    for (int num : a) {
        uniqueElement ^= num;
    }
    return uniqueElement;
}
