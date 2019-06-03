/*A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -¡Þ.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.*/

/*Runtime: 4 ms, faster than 99.32% of C++ online submissions for Find Peak Element.
Memory Usage: 8.5 MB, less than 86.71% of C++ online submissions for Find Peak Element.*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int j = nums.size() - 1;
        if (j == 0)return 0;
        int i = 0;
        while (i<j - 1)
        {
            int m = (i + j) / 2;
            if (nums[m]>nums[m - 1] && nums[m]>nums[m + 1])return m;
            else if (nums[m]>nums[m - 1])i = m;
            else j = m;
        }
        return nums[i]>nums[j] ? i : j;
    }
};