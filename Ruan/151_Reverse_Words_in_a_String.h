/*Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.*/

/*Runtime: 8 ms, faster than 97.01% of C++ online submissions for Reverse Words in a String.
Memory Usage: 9.7 MB, less than 69.06% of C++ online submissions for Reverse Words in a String.*/

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0 || s.find_first_not_of(' ') == string::npos)return "";
        reverse(s.begin(), s.end());
        auto i = s.find_first_not_of(' ');
        if (i != string::npos)s.erase(0, i);
        auto j = s.find_last_not_of(' ');
        if (j != string::npos)s.erase(j + 1);
        int a = 0;
        while (a<s.size())
        {
            auto b = s.find_first_of(' ', a);
            if (b != string::npos)reverse(s.begin() + a, s.begin() + b);
            else
            {
                reverse(s.begin() + a, s.end());
                break;
            }
            a = b;
            b = s.find_first_not_of(' ', a);
            s.erase(a, b - a - 1);
            b = s.find_first_not_of(' ', a);  //删除部分后重新确定位置，这个操作很重要
            a = b;
        }
        return s;
    }
};