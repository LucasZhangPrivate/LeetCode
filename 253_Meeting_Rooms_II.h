/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1*/

/*Runtime: 24 ms, faster than 32.68% of C++ online submissions for Meeting Rooms II.
Memory Usage: 13.4 MB, less than 7.33% of C++ online submissions for Meeting Rooms II.*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty())return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) {
            return l[0] < r[0];
        });

        struct cmp {
            bool operator()(const vector<int>& l, const vector<int>& r)
            {
                return l[1] > r[1];
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, cmp> q;
        q.push(intervals[0]);
        for (int i = 1; i< intervals.size(); ++i)
        {
            auto a = q.top();
            q.pop();
            if (intervals[i][0] >= a[1])
            {
                a[1] = intervals[i][1];
            }
            else
            {
                q.push(intervals[i]);
            }
            q.push(a);
        }
        return q.size();
    }
};