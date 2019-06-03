/*Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.*/

/*Runtime: 12 ms, faster than 98.10% of C++ online submissions for Basic Calculator II.
Memory Usage: 11 MB, less than 29.05% of C++ online submissions for Basic Calculator II.*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        for (int i = 0; i<s.size(); ++i)
        {
            if (s[i] >= '0'&& s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            if ((s[i]<'0' || s[i]>'9') && s[i] != ' ' || i == s.size() - 1) //這裏需要注意去除空格影响，和最后一个数字的判定
            {
                if (sign == '+')stk.push(num);
                if (sign == '-')stk.push(-num);
                if (sign == '*')
                {
                    num = stk.top()*num;
                    stk.pop();
                    stk.push(num);
                }
                if (sign == '/')
                {
                    num = stk.top() / num;
                    stk.pop();
                    stk.push(num);
                }
                num = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }