/*Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0;
        int runningSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < A.size(); i++) {
            runningSum += A[i];
            res += mp[(runningSum % K + K) % K];
            mp[(runningSum % K + K) % K]++;
        }
        return res;
    }
};