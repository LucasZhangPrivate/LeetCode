/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]*/

/*Runtime: 12 ms, faster than 99.76% of C++ online submissions for Move Zeroes.
Memory Usage: 9.6 MB, less than 31.48% of C++ online submissions for Move Zeroes.*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j< nums.size(); ++j)
        {
            if (nums[j] != 0)
            {
                nums[i++] = nums[j];
            }
        }
        while (i<nums.size())
        {
            nums[i++] = 0;
        }
    }
};