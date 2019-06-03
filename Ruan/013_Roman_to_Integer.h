/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.*/

/*Runtime: 12 ms, faster than 95.12% of C++ online submissions for Roman to Integer.
Memory Usage: 10.4 MB, less than 71.57% of C++ online submissions for Roman to Integer.*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },
        { 'L', 50 },{ 'C', 100 },{ 'D',500 },
        { 'M', 1000 } };
        int res = 0;
        if (s.empty()) return 0;
        if (s.size() == 1)return map[s[0]];
        int pre = map[s[0]];
        for (int i = 1; i<s.size(); ++i)
        {
            if (s[i] == s[i - 1])pre += map[s[i]];
            else if (map[s[i]] < map[s[i - 1]])
            {
                res += pre;
                pre = map[s[i]];
            }
            else
            {
                res -= pre;
                pre = map[s[i]];
            }
        }
        res += pre;
        return res;
    }
};




class Solution {
public:
    int romanToInt(string s)
    {
        int ans = 0;
        unordered_map<char, int> sign;
        sign['I'] = 1;
        sign['V'] = 5;
        sign['X'] = 10;
        sign['L'] = 50;
        sign['C'] = 100;
        sign['D'] = 500;
        sign['M'] = 1000;
        for (int i = 0; i<s.size(); i++)
        {
            ans += sign[s[i]];
            if (i>0 && sign[s[i]]>sign[s[i - 1]])
                ans -= 2 * sign[s[i - 1]];
        }
        return ans;
    }
};