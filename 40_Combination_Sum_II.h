/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]*/

/*Runtime: 24 ms, faster than 27.56% of C++ online submissions for Combination Sum II.
Memory Usage: 14.5 MB, less than 18.33% of C++ online submissions for Combination Sum II.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& candidates, int cur, int target, vector<int> temp)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (cur >= candidates.size() || target < 0)return;
        for (int i = cur; i< candidates.size(); ++i)
        {
            temp.push_back(candidates[i]);
            help(res, candidates, i + 1, target - candidates[i], temp);
            temp.pop_back();
            while (i + 1<candidates.size() && candidates[i] == candidates[i + 1])i++; //这里最重要，是为了去重
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        help(res, candidates, 0, target, temp);
        return res;
    }
};