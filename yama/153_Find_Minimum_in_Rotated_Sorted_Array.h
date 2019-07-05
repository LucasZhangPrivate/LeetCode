/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array.
Memory Usage: 8.7 MB, less than 55.17% of C++ online submissions for Find Minimum in Rotated Sorted Array.*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            int mi = (j + i) / 2;
            if (nums[mi] > nums[j])i = mi + 1;
            else j = mi;
        }
        return nums[i];
    }
};