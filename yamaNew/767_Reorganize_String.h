/*Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
 */

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reorganize String.
Memory Usage: 8.7 MB, less than 39.37% of C++ online submissions for Reorganize String.*/

class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() <= 1)return S;
        vector<pair<char, int>> m;
        for (int i = 0; i<26; ++i)
        {
            m.push_back({ 'a' + i, 0 });
        }
        for (const auto& c : S)
        {
            m[c - 'a'].second++;
        }
        sort(m.begin(), m.end(), [](const auto& l, const auto& r) {
            return l.second > r.second;
        });
        string temp;
        for (auto& n : m)
        {
            if (n.second == 0)break;
            while (n.second-->0)temp += n.first;
        }

        string res;
        int l = temp.size() - 1;
        int mid = (0 + l) / 2 + 1;
        if (temp[0] == temp[mid])return res;  //×¢Òâß@ÑYµÄÅÐ”à
        for (int i = 0; i <= (temp.size() - 1) / 2; ++i)
        {
            res += temp[i];
            if (mid + i<temp.size())res += temp[mid + i];
        }
        return res;
    }
};