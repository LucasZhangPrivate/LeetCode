/*Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ¡Ý k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/

/*Runtime: 12 ms, faster than 48.24% of C++ online submissions for Remove K Digits.
Memory Usage: 27.9 MB, less than 13.58% of C++ online submissions for Remove K Digits.*/

class Solution {
public:
    string help(string& num, int k)
    {
        if (k == 0)return num;
        auto i = num.find_first_of('0');
        if (i != string::npos && i <= k)
        {
            k -= i;
            num = num.substr(i + 1);
            int j = 0;
            while (j<num.size())
            {
                if (num[j] == '0')++j;
                else break;
            }
            if (j == num.size())return "0";
            else {
                num = num.substr(j);
                return help(num, k);
            }
        }
        else
        {
            for (int j = 0; j<num.size(); ++j)
            {
                if (j<num.size() - 1 && num[j]>num[j + 1])
                {
                    num = num.substr(0, j) + num.substr(j + 1);
                    return help(num, k - 1);
                }
            }
            num = num.substr(0, num.size() - 1);
            return help(num, k - 1);
        }

    }


    string removeKdigits(string num, int k) {
        if (num.size() <= k)return "0";
        return help(num, k);

    }
};