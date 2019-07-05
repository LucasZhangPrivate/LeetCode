/*Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        bool mark = false;
        for (const auto& c : s)
        {
            mp[c]++;
        }
        for (const auto& n : mp)
        {
            if (n.second % 2 == 1)
            {
                if (mark)return false;
                else mark = true;
            }
        }
        return true;
    }
};