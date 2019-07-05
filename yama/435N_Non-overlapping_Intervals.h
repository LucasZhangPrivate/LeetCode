/*Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 

Example 1:

Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 

Example 2:

Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 

Example 3:

Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.*/

/*Runtime: 396 ms, faster than 5.05% of C++ online submissions for Non-overlapping Intervals.
Memory Usage: 11.7 MB, less than 19.82% of C++ online submissions for Non-overlapping Intervals.*/

class Solution {
public:
    bool overlap(const vector<int>& l, const vector<int>& r)
    {
        return l[1]>r[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) {
            return l[0]<r[0];
        });
        vector<int> dp(intervals.size(), 0);
        dp[0] = 1;
        int temp = 1;
        for (int i = 1; i<intervals.size(); ++i)
        {
            int m = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (!overlap(intervals[j], intervals[i]))m = max(dp[j], m);
            }
            dp[i] = m + 1;
            temp = max(temp, dp[i]);
        }
        return intervals.size() - temp;
    }
};