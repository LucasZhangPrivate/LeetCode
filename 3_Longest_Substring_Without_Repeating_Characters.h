/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

/*Runtime: 28 ms, faster than 53.78% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 11.6 MB, less than 64.54% of C++ online submissions for Longest Substring Without Repeating Characters.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<2) return s.size();
        unordered_map<char, int> map;
        int res = 0;
        int i = 0;
        int j = 0;
        while (i< s.size())
        {
            if (map.find(s[i]) == map.end())
            {
                res = max(res, i - j + 1);
                map[s[i]] = 1;
                i++;
            }
            else
            {
                map[s[i++]] ++;
                while (j<i)
                {
                    if (map[s[j]] == 2)
                    {
                        map[s[j]] = 1;
                        j++;
                        break;
                    }
                    else map.erase(s[j++]);
                }
            }
        }
        return res;
    }
};

/*Runtime: 4 ms, faster than 99.84% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.7 MB, less than 78.83% of C++ online submissions for Longest Substring Without Repeating Characters.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> check(256, -1);
        int longest = 0;
        int start = 0;
        for (int i = 0; i<s.size(); ++i)
        {
            if (check[s[i]] == -1)
            {
                longest = max(longest, i - start + 1);
                check[s[i]] = i;

            }
            else
            {
                longest = max(longest, i - max(start, check[s[i]] + 1) + 1);
                start = max(start, check[s[i]] + 1);
                check[s[i]] = i;
            }
        }
        return longest;
    }
};