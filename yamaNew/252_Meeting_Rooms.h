/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.*/

/*Runtime: 20 ms, faster than 62.99% of C++ online submissions for Meeting Rooms.
Memory Usage: 11.8 MB, less than 37.76% of C++ online submissions for Meeting Rooms.*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) {
            if (l[0] == r[0])return l[1] < r[1];
            return l[0]<r[0];
        });
        for (int i = 1; i< intervals.size(); ++i)
        {
            if (intervals[i][0]<intervals[i - 1][1])return false;
        }
        return true;
    }
};