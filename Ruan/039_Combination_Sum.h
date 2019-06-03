/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/

/*Runtime: 44 ms, faster than 24.95% of C++ online submissions for Combination Sum.
Memory Usage: 17.4 MB, less than 22.42% of C++ online submissions for Combination Sum.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int> temp, vector<int>& candidates, int cur, int target)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (target < 0 || cur >= candidates.size())return;
        for (int i = cur; i< candidates.size(); ++i)
        {
            temp.push_back(candidates[i]);
            help(res, temp, candidates, i, target - candidates[i]);
            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        help(res, temp, candidates, 0, target);
        return res;
    }
};