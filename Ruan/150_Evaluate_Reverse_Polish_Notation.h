/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22*/

/*Runtime: 8 ms, faster than 99.90% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 11.6 MB, less than 45.32% of C++ online submissions for Evaluate Reverse Polish Notation.*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stk;
        for (const auto& t : tokens)
        {
            if (t.size() == 1 && t[0]<'0' || t[0]>'9')
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                if (t == "+")stk.push(first + second);
                else if (t == "-")stk.push(first - second);
                else if (t == "*")stk.push(first * second);
                else stk.push(first / second);
            }
            else stk.push(atoi(t.c_str()));
        }
        return stk.top();
    }
};

/*Runtime: 16 ms, faster than 84.59% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 14.8 MB, less than 5.08% of C++ online submissions for Evaluate Reverse Polish Notation.*/

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        string a = tokens.back();
        tokens.pop_back();
        if (a == "+" || a == "-" || a == "*" || a == "/")
        {
            int y = evalRPN(tokens);
            int x = evalRPN(tokens);
            if (a == "+")return x + y;
            else if (a == "-")return x - y;
            else if (a == "*")return x * y;
            else return x / y;
        }
        else return stoi(a);
    }
};