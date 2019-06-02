/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.*/

/*Runtime: 4 ms, faster than 91.35% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 9.8 MB, less than 5.09% of C++ online submissions for Letter Combinations of a Phone Number.*/

class Solution {
public:
    void help(vector<string>& res, string temp, int cur, string digits, unordered_map<char, string> mp)
    {
        if (cur == digits.size())
        {
            res.push_back(temp);
        }
        auto d = mp[digits[cur]];
        for (int i = 0; i< d.size(); ++i)
        {
            help(res, temp + d[i], cur + 1, digits, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())return res;
        unordered_map<char, string> map{ { '2', "abc" },{ '3', "def" },{ '4',"ghi" },
        { '5', "jkl" },{ '6', "mno" },{ '7', "pqrs" },
        { '8', "tuv" },{ '9', "wxyz" } };


        string temp;
        help(res, temp, 0, digits, map);
        return res;


    }
};