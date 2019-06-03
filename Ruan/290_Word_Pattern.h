/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.*/

/*Runtime: 4 ms, faster than 95.01% of C++ online submissions for Word Pattern.
Memory Usage: 8.7 MB, less than 48.86% of C++ online submissions for Word Pattern.*/


//注意几个容易疏忽的点
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0;
        int j = 0;
        unordered_map<char, string> map;
        unordered_set<string> set;
        while (i<str.size())
        {
            auto it = str.find_first_of(' ', i);
            string s;
            if (it != string::npos)
            {
                s = str.substr(i, it - i);
                i = it + 1;
            }
            else if (i<str.size())
            {
                s = str.substr(i);
                i = str.size();
            }

            auto key = pattern[j];
            if (map.find(key) == map.end())
            {
                if (set.count(s) > 0)return false;  //这里需要查询新的字符串是否已经存在
                map[key] = s;
                set.insert(s);
            }
            else
            {
                if (map[key] != s)return false;
            }

            ++j;
        }
        return j == pattern.size(); //这里需要确认pattern和string匹配。
    }
};