/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

/*Runtime: 4 ms, faster than 96.89% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 9.3 MB, less than 12.11% of C++ online submissions for Maximum Product Subarray.*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int big = nums[0];
        int small = nums[0];
        int res = nums[0];
        for (int i = 1; i<nums.size(); ++i)
        {
            int a = max(small*nums[i], big*nums[i]);
            int b = min(small*nums[i], big*nums[i]);
            big = max(a, nums[i]);
            small = min(b, nums[i]);
            res = max(res, big);
        }
        return res;
    }
};