/*Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Solve the Equation.
Memory Usage: 8.4 MB, less than 54.35% of C++ online submissions for Solve the Equation.*/

class Solution {

public:
    pair<int, int> help(string in)
    {
        in.push_back(' ');
        int sum = 0;
        int sumX = 0;
        int sign = 1;
        int num = 0;
        bool x = false;
        for (int i = 0; i<in.size(); ++i)
        {
            if (in[i] == '+' || in[i] == '-' || i == in.size() - 1)
            {
                if (x)sumX = sumX + sign * num;
                else sum = sum + sign * num;
                x = false;
                num = 0;
                if (in[i] == '+')sign = 1;
                else sign = -1;
            }
            else if (in[i] == 'x')
            {
                if (num == 0)
                {
                    if (i == 0 || i - 1 >= 0 && in[i - 1] != '0')num = 1;  // 0x = 0
                }
                x = true;
            }
            else
            {
                num = num * 10 + in[i] - '0';
            }
        }
        return { sum, sumX };
    }
    string solveEquation(string equation) {
        auto i = equation.find('=');
        auto left = equation.substr(0, i);
        auto right = equation.substr(i + 1);
        auto l = help(left);
        auto r = help(right);
        int x = l.second - r.second;
        int n = r.first - l.first;
        if (0 == n && x == 0)return "Infinite solutions";
        else if (x == 0)return "No solution";
        else
        {
            auto res = n / x;
            string ans = "x=" + to_string(res);
            return ans;
        }
    }
};