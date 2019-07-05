/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

Accepted
39,761
Submissions
92,852*/

/*Runtime: 128 ms, faster than 68.26% of C++ online submissions for Contiguous Array.
Memory Usage: 19.7 MB, less than 74.19% of C++ online submissions for Contiguous Array.*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int sum = 0;
        for (int i = 0; i<nums.size(); ++i)
        {
            if (nums[i] == 0)sum -= 1;
            else sum += 1;
            if (sum == 0)
            {
                res = i + 1;
            }
            else if (mp.count(sum))
            {
                res = max(res, i - mp[sum]);
            }
            else mp[sum] = i;
        }
        return res;
    }
};