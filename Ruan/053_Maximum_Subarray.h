/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.*/

/*Runtime: 8 ms, faster than 93.76% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.3 MB, less than 67.75% of C++ online submissions for Maximum Subarray.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)return nums[0];
        int res = nums[0];
        for (int i = 1; i<nums.size(); ++i)
        {
            if (nums[i] + nums[i - 1] > nums[i])
            {
                nums[i] = nums[i] + nums[i - 1];
            }
            res = max(res, nums[i]);   //注意这个要在if外
        }
        return res;
    }
};

//四年前的，貌似更简洁
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)return 0;
        if (nums.size() == 1)return nums[0];
        int result = nums[0];
        int size = nums.size();
        for (int i = 1; i<size; i++)
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            result = max(result, nums[i]);
        }
        return result;
    }
};