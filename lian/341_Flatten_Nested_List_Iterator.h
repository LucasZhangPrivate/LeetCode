/*Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].*/

/*Runtime: 20 ms, faster than 91.26% of C++ online submissions for Flatten Nested List Iterator.
Memory Usage: 18.9 MB, less than 25.25% of C++ online submissions for Flatten Nested List Iterator.*/

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedIterator {
private:
    vector<int> list;
    int index;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        flat(nestedList);
    }

    void flat(vector<NestedInteger> &nestedList)
    {
        vector<NestedInteger> nList;
        for (const auto& n : nestedList)
        {
            if (n.isInteger())
            {
                list.push_back(n.getInteger());
            }
            else
            {
                auto i = n.getList();
                flat(i);
            }
        }
    }

    int next() {
        return list[index++];
    }

    bool hasNext() {
        return index<list.size();
    }
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/