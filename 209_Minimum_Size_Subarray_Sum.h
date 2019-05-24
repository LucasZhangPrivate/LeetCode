/*Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). */

/*Runtime: 8 ms, faster than 99.07% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.1 MB, less than 25.14% of C++ online submissions for Minimum Size Subarray Sum.*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j< nums.size())
        {
            while (sum<s && j<nums.size())
            {
                sum += nums[j++];
            }
            if (sum >= s)
            {
                res = min(res, j - i);
            }
            while (sum - nums[i] >= s && i<j)
            {
                sum -= nums[i++];
            }
            if (sum >= s)
            {
                res = min(res, j - i);
                sum -= nums[i++];
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};

//º†»¯°æ
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (j< nums.size())
        {
            sum += nums[j++];
            while (sum >= s)
            {
                res = min(res, j - i);
                sum -= nums[i++];
            }

        }
        return res == nums.size() + 1 ? 0 : res;
    }
};