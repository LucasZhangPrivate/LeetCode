/*Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/

/*Runtime: 8 ms, faster than 89.89% of C++ online submissions for Subsets II.
Memory Usage: 9.5 MB, less than 46.83% of C++ online submissions for Subsets II.*/

class Solution {
public:
    void sub(vector<vector<int>>& res, vector<int>& nums, vector<int> cur, int start)
    {
        if (start >= nums.size())return;
        for (int i = start; i<nums.size(); ++i)
        {
            if (i>start && nums[i] == nums[i - 1])continue;
            cur.push_back(nums[i]);
            res.push_back(cur);
            sub(res, nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(cur);
        sort(nums.begin(), nums.end()); //因为这个subset是不看顺序的，所以保证不能出现含同样元素但是顺序不同的结果
        sub(res, nums, cur, 0);
        return res;
    }
};