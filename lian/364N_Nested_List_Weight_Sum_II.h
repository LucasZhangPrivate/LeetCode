/*Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 8 
Explanation: Four 1's at depth 1, one 2 at depth 2.
Example 2:

Input: [1,[4,[6]]]
Output: 17 
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.*/

/*Runtime: 4 ms, faster than 93.07% of C++ online submissions for Nested List Weight Sum II.
Memory Usage: 17.4 MB, less than 5.02% of C++ online submissions for Nested List Weight Sum II.*/

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
    void sum(vector<NestedInteger>& nestedList, int& val)
    {
        vector<NestedInteger> newList;
        bool allint = true;
        for (const auto& n : nestedList)
        {
            if (n.isInteger())
            {
                val += n.getInteger();
                newList.push_back(NestedInteger(n));
            }
            else
            {
                allint = false;
                auto list = n.getList();
                newList.insert(newList.end(), list.begin(), list.end());
            }
        }
        if (allint)return;
        sum(newList, val);
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        sum(nestedList, res);
        return res;
    }
};