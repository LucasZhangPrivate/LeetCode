/*986. Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        size_t i = 0;
        size_t j = 0;
        vector<Interval> result;
        if (A.empty() || B.empty())return result;
        Interval a;
        Interval b = A[i].start<B[j].start ? A[i++] : B[j++];
        while (i<A.size() || j<B.size())
        {
            a = b;
            if (i == A.size()) {
                b = B[j++];
            }
            else if (j == B.size()) {
                b = A[i++];
            }
            else if (A[i].start<B[j].start) {
                b = A[i++];
            }
            else {
                b = B[j++];
            }

            if (b.start <= a.end && b.end >= a.start) {
                Interval temp(max(a.start, b.start), min(a.end, b.end));
                result.push_back(temp);
                b = Interval(min(a.end, b.end), max(a.end, b.end));
            }
            else {
                b = a.start<b.start ? b : a;
            }
        }
        return result;
    }
};