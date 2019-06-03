/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

/*Runtime: 4 ms, faster than 97.10% of C++ online submissions for Generate Parentheses.
Memory Usage: 17.4 MB, less than 32.84% of C++ online submissions for Generate Parentheses.*/

class Solution {
public:
    void help(vector<string>& res, int l, int r, string temp)
    {
        if (l == 0 && r == 0)
        {
            res.push_back(temp);
            return;
        }
        if (l>0)
        {
            help(res, l - 1, r, temp + '(');
        }
        if (r>l)
        {
            help(res, l, r - 1, temp + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        help(res, n, n, temp);
        return res;
    }
};