/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?*/

/*Runtime: 8 ms, faster than 78.57% of C++ online submissions for Search in Rotated Sorted Array II.
Memory Usage: 8.7 MB, less than 56.13% of C++ online submissions for Search in Rotated Sorted Array II.*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] == target)return true;
            if (nums[mid]>nums[j])
            {
                if (target >= nums[i] && target<nums[mid])j = mid - 1;
                else i = mid + 1;
            }
            else if (nums[mid]<nums[j])
            {
                if (target>nums[mid] && target <= nums[j])i = mid + 1;
                else j = mid - 1;
            }
            else j--;
        }
        return false;
    }
};