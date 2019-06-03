/*Given two positive integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]*/

//corner case, x ==1 or y == 1 need to manual break, or it will loop forever
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int x1 = 1;
        int y1;
        unordered_set<int> s;
        vector<int> result;
        while (true)
        {
            y1 = 1;
            while (true)
            {
                if (x1 + y1 <= bound)s.insert(x1 + y1);
                else break;
                if (y == 1)break;
                y1 *= y;
            }
            x1 *= x;
            if ((x1 + 1)>bound || x == 1)break;
        }
        for (const auto& i : s)result.push_back(i);
        return result;
    }
};