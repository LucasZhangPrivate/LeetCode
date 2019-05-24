/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false*/
/*Runtime: 16 ms, faster than 94.21% of C++ online submissions for Contains Duplicate III.
Memory Usage: 11.1 MB, less than 10.70% of C++ online submissions for Contains Duplicate III.*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> set;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (set.size() == k + 1)set.erase(set.find(nums[i - k - 1]));
            auto dif = (long long)nums[i] - (long long)t;
            auto it = set.lower_bound(dif);
            if (it != set.end() && *it - nums[i] <= t)return true;
            set.insert(nums[i]);
        }
        return false;
    }
};