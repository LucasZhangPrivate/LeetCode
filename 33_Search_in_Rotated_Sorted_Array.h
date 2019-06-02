/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1*/

/*Runtime: 4 ms, faster than 95.50% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 8.9 MB, less than 54.74% of C++ online submissions for Search in Rotated Sorted Array.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)return -1;
        int begin = 0;
        int end = size - 1;
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] <= nums[end])   //must <= not <
            {
                if (target == nums[mid])return mid;
                if (target == nums[end])return end;
                if (target>nums[mid] && target<nums[end])
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
            else if (nums[mid]>nums[end])
            {
                if (target == nums[mid])return mid;
                if (target == nums[begin])return begin;
                if (target>nums[begin] && target<nums[mid])
                    end = mid - 1;
                else
                    begin = mid + 1;
            }
        }
        return -1;

    }
};