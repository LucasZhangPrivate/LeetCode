/*Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]*/

/*Runtime: 52 ms, faster than 31.73% of C++ online submissions for 4Sum.
Memory Usage: 9.3 MB, less than 65.06% of C++ online submissions for 4Sum.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i + 3< nums.size(); ++i)
        {
            for (int j = nums.size() - 1; i + 2 < j; --j)
            {
                int m = i + 1;
                int n = j - 1;
                while (m<n)
                {
                    auto sum = nums[i] + nums[m] + nums[n] + nums[j];
                    if (sum == target)
                    {
                        res.push_back({ nums[i], nums[m], nums[n], nums[j] });
                        while (m<n && nums[m] == nums[m + 1])m++;
                        while (m<n && nums[n] == nums[n - 1])n--;
                        m++;
                        n--;
                    }
                    else if (sum < target)
                    {
                        while (m<n && nums[m] == nums[m + 1])m++;
                        m++;
                    }
                    else
                    {
                        while (m<n && nums[n] == nums[n - 1])n--;
                        n--;
                    }
                }
                while (i + 2<j && nums[j] == nums[j - 1])j--;

            }
            while (i<nums.size() - 3 && nums[i] == nums[i + 1])i++;
        }

        return res;
    }
};