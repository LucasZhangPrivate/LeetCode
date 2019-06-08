/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]*/

/*Runtime: 24 ms, faster than 85.76% of C++ online submissions for Permutations II.
Memory Usage: 11.2 MB, less than 21.57% of C++ online submissions for Permutations II.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& nums, int begin)
    {
        if (begin >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for (int i = begin; i<nums.size(); ++i)
        {
            if (set.count(nums[i]))continue;
            set.insert(nums[i]);
            swap(nums[begin], nums[i]);
            help(res, nums, begin + 1);
            swap(nums[begin], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        help(res, nums, 0);
        return res;
    }
};