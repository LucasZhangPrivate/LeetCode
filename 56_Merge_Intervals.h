/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.*/

/*Runtime: 12 ms, faster than 99.37% of C++ online submissions for Merge Intervals.
Memory Usage: 12.6 MB, less than 11.44% of C++ online submissions for Merge Intervals.*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)return intervals;
        sort(intervals.begin(), intervals.end(),
            [](const auto& l, const auto& r)->bool {return l[0]<r[0]; });

        vector<vector<int>> res;
        auto pre = intervals[0];
        for (int i = 1; i<intervals.size(); ++i)
        {
            if (intervals[i][0] <= pre[1])
            {
                pre[1] = max(pre[1], intervals[i][1]);
            }
            else
            {
                res.push_back(pre);
                pre = intervals[i];
            }
        }
        res.push_back(pre);
        return res;
    }
};