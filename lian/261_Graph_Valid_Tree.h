/*Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.*/

/*Runtime: 24 ms, faster than 43.76% of C++ online submissions for Graph Valid Tree.
Memory Usage: 11.9 MB, less than 42.68% of C++ online submissions for Graph Valid Tree.*/

class Solution {
public:
    int getP(vector<int>& p, int i)
    {
        while (i != p[i])
        {
            i = p[i];
        }
        return i;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> p(n, 0);
        for (int i = 0; i<n; ++i)p[i] = i;
        for (const auto& e : edges)
        {
            int pre = e[0];
            int post = e[1];
            int preP = getP(p, pre);
            int postP = getP(p, post);
            if (preP == postP)return false;
            p[postP] = preP;
        }
        return edges.size() == n - 1;
    }
};