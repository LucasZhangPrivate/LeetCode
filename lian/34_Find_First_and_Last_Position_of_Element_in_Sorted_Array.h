/*iven an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

/*Runtime: 8 ms, faster than 95.21% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 10.3 MB, less than 75.79% of C++ online submissions for Find First and Last Position of Element in Sorted Array.*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] == target)
            {
                start = mid;
                end = mid;
                break;
            }
            else if (target>nums[mid])
            {
                i = mid + 1;
            }
            else j = mid - 1;
        }
        if (start != -1)
        {
            while (start - 1 >= 0 && nums[start - 1] == target)
            {
                start--;
            }
            while (end + 1<nums.size() && nums[end + 1] == target)
            {
                end++;
            }
        }
        return { start, end };
    }
};