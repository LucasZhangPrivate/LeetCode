/*Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.*
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets./

/*Runtime: 76 ms, faster than 59.20% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 9.2 MB, less than 50.40% of C++ online submissions for Partition Equal Subset Sum.*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num : nums) total += num;

        if (total % 2 != 0) return false;
        int i, j;
        vector<int> dp = vector<int>((total / 2) + 1, 0);
        for (i = 0; i < nums.size(); i++) {
            for (j = total / 2; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }

        return (dp[total / 2] == total / 2);

    }
};

