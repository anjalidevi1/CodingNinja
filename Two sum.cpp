//You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
Note:
We cannot use the element at a given index twice.
Follow Up:

Try to do this problem in O(N) time complexity. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105

Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.
Time Limit: 1 sec.
Sample Input 1 :
2
4 9
2 7 11 13
5 1
1 -1 -1 2 2
Sample Output 1:
2 7
-1 2
-1 2
Explanation for Sample 1:
For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.
For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
Sample Input 2 :
1
4 16
2 7 11 13
Sample Output 2 :
-1 -1




#include <bits/stdc++.h>
vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n) {
    unordered_map<int, int> seen; // To store elements and their counts
    vector<pair<int, int>> pairs; // To store the result pairs

    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        int complement = target - num;

        // Check if the complement exists in the seen map
        if (seen[complement] > 0) {
            pairs.push_back({complement, num});
            seen[complement]--;
        } else {
            seen[num]++;
        }
    }

    // If no pairs were found, return {-1, -1}
    if (pairs.empty()) {
        pairs.push_back({-1, -1});
    }

    return pairs;
}
