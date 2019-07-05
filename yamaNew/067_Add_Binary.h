/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/

/*Runtime: 8 ms, faster than 42.95% of C++ online submissions for Add Binary.
Memory Usage: 9.4 MB, less than 13.85% of C++ online submissions for Add Binary.*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res;
        while (i >= 0 || j >= 0 || carry>0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += (a[i--] - '0');
            }
            if (j >= 0)
            {
                sum += (b[j--] - '0');
            }
            int cur = sum % 2;
            res = to_string(cur) + res;
            carry = sum / 2;
        }
        return res;
    }
};