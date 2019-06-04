/*Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.*/

/*Runtime: 64 ms, faster than 20.91% of C++ online submissions for Partition to K Equal Sum Subsets.
Memory Usage: 35.5 MB, less than 6.51% of C++ online submissions for Partition to K Equal Sum Subsets.*/

class Solution {
public:
    bool partition(vector<int>& nums, int pos, int k, int K, int sum, int T, unordered_set<int> visited)
    {
        if (k == K)
            return true;

        if (sum == T) {
            return partition(nums, 0, k + 1, K, 0, T, visited);
        }

        for (int i = pos; i < nums.size(); ++i) {
            if (!visited.count(i) && nums[i] <= T - sum) {
                visited.insert(i);
                if (partition(nums, i + 1, k, K, sum + nums[i], T, visited))
                    return true;
                visited.erase(i);
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int ma = 0;
        for (const auto& n : nums)
        {
            sum += n;
            ma = max(ma, n);
        }
        if (sum%k != 0) return false;
        int s = sum / k;
        if (ma > s)return false;

        bool mark = false;
        int temp = 0;
        unordered_set<int> index;

        return partition(nums, 0, 1, k, 0, s, index);
    }
};