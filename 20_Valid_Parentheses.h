/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true*/

/*Runtime: 4 ms, faster than 91.16% of C++ online submissions for Valid Parentheses.
Memory Usage: 8.5 MB, less than 64.42% of C++ online submissions for Valid Parentheses.*/

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())return true;
        if (s.size() % 2 == 1) return false;
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i<s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')stk.push(s[i]);
            else
            {
                if (stk.empty())return false;
                auto temp = stk.top();
                if (temp == '(' && s[i] == ')' || temp == '['&& s[i] == ']'
                    || temp == '{' && s[i] == '}')
                {
                    stk.pop();
                }
                else return false;
            }
        }
        return stk.empty();
    }
};