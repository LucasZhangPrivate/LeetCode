/*Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.*/

/*Runtime: 4 ms, faster than 99.11% of C++ online submissions for Largest Number.
Memory Usage: 10.8 MB, less than 5.05% of C++ online submissions for Largest Number.*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (const auto& n : nums)
        {
            s.push_back(to_string(n));
        }

        sort(s.begin(), s.end(), [](const auto& l, const auto& r) { //注意这个比较函数
            auto a = l + r;
            auto b = r + l;
            return a>b;
        });
        string res;
        for (const auto& n : s)res = res + n;
        if (atoi(res.c_str()) == 0)return "0"; //排除corner case

        return res;

    }
};