/*Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].*/

/*Runtime: 196 ms, faster than 62.30% of C++ online submissions for Daily Temperatures.
Memory Usage: 16.3 MB, less than 35.52% of C++ online submissions for Daily Temperatures.*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> stk;
        if (T.size() == 1)return res;
        stk.push(0);
        for (int i = 1; i<T.size(); ++i)
        {
            while (!stk.empty() && T[i]>T[stk.top()])
            {
                auto index = stk.top();
                stk.pop();
                res[index] = i - index;
            }
            stk.push(i);
        }
        return res;
    }
};