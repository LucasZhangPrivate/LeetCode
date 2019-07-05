/*Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.*/

/*Runtime: 84 ms, faster than 63.19% of C++ online submissions for All Paths From Source to Target.
Memory Usage: 17.2 MB, less than 36.13% of C++ online submissions for All Paths From Source to Target.*/

class Solution {
public:
    void help(vector<vector<int>>& graph, vector<int> path, int cur, vector<vector<int>>& res)
    {
        if (cur == graph.size() - 1)
        {
            res.push_back(path);
            return;
        }
        auto nodes = graph[cur];
        for (const auto& n : nodes)
        {
            path.push_back(n);
            help(graph, path, n, res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path({ 0 });
        help(graph, path, 0, res);
        return res;
    }
};