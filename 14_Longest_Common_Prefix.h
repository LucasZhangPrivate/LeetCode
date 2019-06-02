/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.*/

/*Runtime: 8 ms, faster than 88.44% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9 MB, less than 62.25% of C++ online submissions for Longest Common Prefix.*/

class Solution {
public:
    int common(const string& l, const string& r)
    {
        if (l.empty() || r.empty())return -1;
        int i = 0;
        while (i<l.size() && i< r.size())
        {
            if (l[i] == r[i])i++;
            else break;
        }
        return i - 1;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)return "";
        if (strs.size() == 1) return strs[0];
        string res = strs[0];
        for (int i = 1; i<strs.size(); ++i)
        {
            int index = common(res, strs[i]);
            if (index == -1)return "";
            res = res.substr(0, 1 + index);
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string result;
        if (strs.size() == 0)return result;
        if (strs.size() == 1)return strs[0];
        result = strs[0];
        int i = 1;
        while (i<strs.size())
        {
            int j = 0;
            while (j<result.size())
            {
                if (result[j] != strs[i][j])
                    break;
                else j++;
            }
            result = result.substr(0, j);
            i++;
        }
        return result;
    }
};