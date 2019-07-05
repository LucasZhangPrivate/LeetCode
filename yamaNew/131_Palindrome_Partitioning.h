/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]*/

/*Runtime: 52 ms, faster than 44.45% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 19.3 MB, less than 57.43% of C++ online submissions for Palindrome Partitioning.*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        dfs(result, s, 0, temp);
        return result;
    }

    void dfs(vector<vector<string>>& res, string s, int start, vector<string>& temp)
    {
        if (start >= s.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 1; i + start <= s.size(); ++i)
        {
            if (isp(s.substr(start, i)))
            {
                temp.push_back(s.substr(start, i));
                dfs(res, s, start + i, temp);
                temp.pop_back();
            }
        }

    }
    bool isp(const string& s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            if (s[i++] != s[j--])return false;
        }
        return true;
    }
};