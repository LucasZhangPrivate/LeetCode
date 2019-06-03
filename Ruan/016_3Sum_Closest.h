/*Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

/*Runtime: 4 ms, faster than 99.82% of C++ online submissions for 3Sum Closest.
Memory Usage: 8.8 MB, less than 61.72% of C++ online submissions for 3Sum Closest.*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int di = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            int j = i + 1;
            int l = nums.size() - 1;
            while (j < l)
            {
                int temp = nums[i] + nums[j] + nums[l];
                if (temp == target) return temp;
                if (abs(temp - target) < di)
                {
                    res = temp;
                    di = abs(temp - target);
                }
                if (j<l && temp < target)j++;
                if (j<l && temp > target)l--;
            }
        }
        return res;
    }
};