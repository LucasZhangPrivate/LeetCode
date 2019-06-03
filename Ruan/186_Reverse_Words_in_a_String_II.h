/*Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?*/

/*Runtime: 60 ms, faster than 95.98% of C++ online submissions for Reverse Words in a String II.
Memory Usage: 16.3 MB, less than 55.91% of C++ online submissions for Reverse Words in a String II.*/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int i = 0;
        int j = 0;
        while (j< str.size())
        {
            while (j < str.size() && str[j] != ' ')++j;
            if (j<str.size())
            {
                reverse(str.begin() + i, str.begin() + j);
                ++j;
                i = j;
            }
            else
            {
                reverse(str.begin() + i, str.end());
            }
        }
    }
};