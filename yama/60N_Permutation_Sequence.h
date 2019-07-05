/*The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"*/

/*Runtime: 4 ms, faster than 80.70% of C++ online submissions for Permutation Sequence.
Memory Usage: 8.3 MB, less than 20.51% of C++ online submissions for Permutation Sequence.*/

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        int fac = 1;
        for (int i = 2; i < n; i++) {
            fac *= i;
        }
        string res;
        int round = n - 1;
        while (round >= 0) {
            int index = k / fac;
            k %= fac;
            res += nums[index] + '0';
            nums.erase(nums.begin() + index);
            if (round) {
                fac /= round;
            }
            round--;
        }
        return res;
    }

};