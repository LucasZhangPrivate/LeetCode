/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

/*Runtime: 88 ms, faster than 99.65% of C++ online submissions for 3Sum.
Memory Usage: 14.7 MB, less than 78.40% of C++ online submissions for 3Sum.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            int j = i + 1;
            int z = nums.size() - 1;
            while (j<z)
            {
                int sum = nums[i] + nums[j] + nums[z];
                if (sum == 0)
                {
                    res.push_back({ nums[i], nums[j], nums[z] });
                    while (j<z && nums[j] == nums[j + 1])j++;
                    while (j<z && nums[z] == nums[z - 1])z--;
                    j++;
                    z--;
                }
                else if (sum<0)j++;
                else z--;
            }
            while (i + 1<nums.size() && nums[i] == nums[i + 1])i++;
        }
        return res;
    }
};