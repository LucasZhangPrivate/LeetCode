/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false*/

/*Runtime: 8 ms, faster than 96.25% of C++ online submissions for Valid Palindrome.
Memory Usage: 9.5 MB, less than 17.79% of C++ online submissions for Valid Palindrome.*/

class Solution {
public:
    bool isAlpha(const char& c)
    {
        if (c >= 'a' && c <= 'z')return true;
        else if (c >= 'A' && c <= 'Z') return true;
        else if (c >= '0' && c <= '9') return true;
        else return false;
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i<j)
        {
            while (i<s.size() && !isAlpha(s[i]))i++;
            while (j >= 0 && !isAlpha(s[j]))j--;
            if (i >= j)break;
            if (tolower(s[i++]) != tolower(s[j--]))return false;
        }
        return true;
    }
};