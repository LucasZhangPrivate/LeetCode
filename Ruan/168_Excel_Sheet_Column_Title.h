/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"*/

/*Runtime: 4 ms, faster than 89.68% of C++ online submissions for Excel Sheet Column Title.
Memory Usage: 8.2 MB, less than 14.41% of C++ online submissions for Excel Sheet Column Title.*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n>0)
        {
            int i = (n - 1) % 26;
            char c = 'A' + i;
            res = c + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};