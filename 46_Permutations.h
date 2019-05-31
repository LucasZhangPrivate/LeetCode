/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

/*Runtime: 12 ms, faster than 93.25% of C++ online submissions for Permutations.
Memory Usage: 12.4 MB, less than 5.01% of C++ online submissions for Permutations.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& nums, vector<int> temp, unordered_set<int> s)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i<nums.size(); ++i)
        {
            if (s.count(nums[i]))continue;
            s.insert(nums[i]);
            temp.push_back(nums[i]);
            help(res, nums, temp, s);
            temp.pop_back();
            s.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> s;
        vector<vector<int>> res;
        if (nums.empty())return res;
        vector<int> temp;
        help(res, nums, temp, s);
        return res;
    }
};

/*Runtime: 12 ms, faster than 93.25% of C++ online submissions for Permutations.
Memory Usage: 9.2 MB, less than 75.78% of C++ online submissions for Permutations.*/

//很久以前参考别人的，这个比较巧妙，节省内存
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            swap(num[begin], num[i]);
        }
    }
};