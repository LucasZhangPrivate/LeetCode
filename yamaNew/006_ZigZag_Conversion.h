/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I*/

/*Runtime: 8 ms, faster than 96.03% of C++ online submissions for ZigZag Conversion.
Memory Usage: 12.7 MB, less than 27.60% of C++ online submissions for ZigZag Conversion.*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        vector<string> v(numRows, "");
        bool down = true;
        int row = 0;
        for (int i = 0; i<s.size(); ++i)
        {
            v[row].push_back(s[i]);
            if (down)row++;
            else row--;

            if (row >= numRows)
            {
                row = v.size() - 2;
                down = false;
            }
            else if (row<0)
            {
                row = 1;
                down = true;
            }
        }
        string res;
        for (const auto& r : v)res += r;
        return res;

    }
};