/*Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2*/

/*Runtime: 52 ms, faster than 48.81% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 18.3 MB, less than 24.93% of C++ online submissions for Subarray Sum Equals K.*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int sum = 0, cnt = 0, i;
        mp[0]++;
        for (i = 0; i<nums.size(); i++)
        {
            sum += nums[i];
            if (mp[sum - k])
                cnt += mp[sum - k]; // Number of subarray
            mp[sum]++;
        }
        return cnt;
    }
};