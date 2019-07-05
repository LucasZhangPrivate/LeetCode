/*Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []*/

class Solution {
public:
    void make(string s, vector<string>& res, int cur)
    {
        if (cur == s.size())
        {
            res.push_back(s);
            return;
        }
        int i = cur;
        while (i < s.size())
        {
            swap(s[cur], s[i]);
            make(s, res, cur + 1);
            swap(s[cur], s[i]);
            while (i + 1 < s.size() && s[i] == s[i + 1])i++;
            i++;
        }

    }

    vector<string> generatePalindromes(string s) {
        vector<string> res;
        vector<int> n(128, 0);
        sort(s.begin(), s.end());
        string sigle;
        string half;
        int i = 0;
        while (i < s.size())
        {
            auto j = s.find_first_not_of(s[i], i);
            char cur = s[i];
            int num = 0;
            if (j == string::npos)
            {
                num = s.size() - i;
                i = s.size();
            }
            else
            {
                num = j - i;
                i = j;
            }
            if (num % 2 == 1)
            {
                if (!sigle.empty())return res;
                else sigle = cur;
            }
            num /= 2;
            while (num-- > 0)half += cur;
        }
        make(half, res, 0);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        for (auto& line : res)
        {
            auto line2 = line;
            reverse(line2.begin(), line2.end());
            line = line + sigle + line2;
        }
        return res;
    }
};