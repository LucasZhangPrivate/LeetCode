/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.*/

/*Runtime: 264 ms, faster than 5.55% of C++ online submissions for Course Schedule.
Memory Usage: 18.6 MB, less than 8.40% of C++ online submissions for Course Schedule.*/

class Solution {
private:
    unordered_map<int, unordered_set<int>> mp;
    bool circle(int start, int end, vector<bool>& visited)
    {
        if (start == end && visited[start])return true;
        if (!mp.count(start))return false;
        for (const int& cur : mp[start])
        {
            if (visited[cur])continue;
            visited[cur] = true;
            if (circle(cur, end, visited))return true;
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (const auto& p : prerequisites)
        {
            mp[p[0]].insert(p[1]);
        }
        for (int i = 0; i< numCourses; ++i)
        {
            vector<bool> visited(numCourses, false);
            if (circle(i, i, visited))return false;
        }
        return true;
    }
};