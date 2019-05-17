/*Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
Memory Usage: 9.2 MB, less than 15.75% of C++ online submissions for Decode String.*/

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for (int i = 0; i<s.size(); ++i)
        {
            if (s[i] != ']')stk.push(s[i]);
            else
            {
                string str;
                while (stk.top() != '[')
                {
                    str.insert(str.begin(), stk.top());
                    stk.pop();
                }
                stk.pop();
                string num;
                while (!stk.empty() && stk.top() >= '0'&&stk.top() <= '9')
                {
                    num.insert(num.begin(), stk.top());
                    stk.pop();
                }
                int repeat = num.size()>0 ? atoi(num.c_str()) : 1;
                string temp;
                while (repeat-->0)
                {
                    temp += str;
                }
                for (auto& t : temp)stk.push(t);
            }
        }
        string res;
        while (!stk.empty())
        {
            res.insert(res.begin(), stk.top());
            stk.pop();
        }
        return res;
    }
};