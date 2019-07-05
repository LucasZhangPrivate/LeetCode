/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000*/

/*Runtime: 32 ms, faster than 97.19% of C++ online submissions for Max Consecutive Ones.
Memory Usage: 11.8 MB, less than 43.35% of C++ online submissions for Max Consecutive Ones.*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (int i = 0; i<nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                res = max(res, count);
                count = 0;
            }
            else count++;
        }

        return max(res, count);
    }
};