/*Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 10 
Explanation: Four 1's at depth 2, one 2 at depth 1.
Example 2:

Input: [1,[4,[6]]]
Output: 27 
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.*/

/*Runtime: 4 ms, faster than 93.93% of C++ online submissions for Nested List Weight Sum.
Memory Usage: 14.2 MB, less than 40.28% of C++ online submissions for Nested List Weight Sum.*/

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Constructor initializes an empty nested list.
*     NestedInteger();
*
*     // Constructor initializes a single integer.
*     NestedInteger(int value);
*
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Set this NestedInteger to hold a single integer.
*     void setInteger(int value);
*
*     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
*     void add(const NestedInteger &ni);
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class Solution {
public:
    void sum(vector<NestedInteger>& nestedList, int& total, int level)
    {
        for (const auto& l : nestedList)
        {
            if (l.isInteger())
            {
                total += l.getInteger()*level;
            }
            else
            {
                auto list = l.getList();
                sum(list, total, level + 1);
            }
        }
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        sum(nestedList, res, 1);
        return res;
    }
};