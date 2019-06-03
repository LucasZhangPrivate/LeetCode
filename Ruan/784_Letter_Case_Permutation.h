/*Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]*/

/*Runtime: 12 ms, faster than 99.23% of C++ online submissions for Letter Case Permutation.
Memory Usage: 14.5 MB, less than 24.00% of C++ online submissions for Letter Case Permutation.*/


//简单递归
class Solution {
public:
    void trans(string& s, int i, string S, vector<string>& result)
    {
        if (i >= S.size())
        {
            result.push_back(s);
            return;
        }
        auto c = S[i];
        if (c <= 'Z'&&c >= 'A')
        {
            s += tolower(c);
            trans(s, i + 1, S, result);
            s.pop_back();   //这里记得把用过的字符剔除
        }
        else if (c <= 'z'&&c >= 'a')
        {
            s += toupper(c);
            trans(s, i + 1, S, result);
            s.pop_back();
        }
        s += c;
        trans(s, i + 1, S, result);
        s.pop_back();
    }


    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string s;
        trans(s, 0, S, result);
        return result;
    }
};