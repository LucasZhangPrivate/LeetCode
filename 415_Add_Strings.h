/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

/*Runtime: 4 ms, faster than 99.40% of C++ online submissions for Add Strings.
Memory Usage: 9 MB, less than 85.24% of C++ online submissions for Add Strings.*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res;
        while (i >= 0 || j >= 0 || carry >0)
        {
            if (i >= 0)
            {
                carry += num1[i] - '0';
            }
            --i;
            if (j >= 0)
            {
                carry += num2[j] - '0';
            }
            --j;
            auto digit = carry % 10;
            res += '0' + digit;
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};