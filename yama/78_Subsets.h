/*Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

/*Runtime: 4 ms, faster than 98.77% of C++ online submissions for Subsets.
Memory Usage: 9 MB, less than 81.02% of C++ online submissions for Subsets.*/

class Solution {
public:
    void sub(vector<vector<int>>& res, const vector<int>& nums, int start, vector<int>& temp)
    {
        if (start >= nums.size())return;
        for (int i = start; i<nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            res.push_back(temp);
            sub(res, nums, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        sub(res, nums, 0, temp);
        return res;
    }
};