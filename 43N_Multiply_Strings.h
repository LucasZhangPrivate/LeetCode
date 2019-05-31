/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/

/*Runtime: 4 ms, faster than 98.93% of C++ online submissions for Multiply Strings.
Memory Usage: 8.7 MB, less than 86.62% of C++ online submissions for Multiply Strings.*/

//没啥好说的，就是把边界硬记住了
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
                res[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            if (carry)res[i] = carry + '0';
        }
        auto it = res.find_first_not_of('0');
        if (it == string::npos) return "0";
        else return res.substr(it);
    }
};