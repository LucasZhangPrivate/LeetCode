/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.*/

/*Runtime: 88 ms, faster than 5.15% of C++ online submissions for Number of Connected Components in an Undirected Graph.
Memory Usage: 12.6 MB, less than 39.37% of C++ online submissions for Number of Connected Components in an Undirected Graph.*/

class Solution {
private:
    unordered_map<int, int> pare;
    int res;
public:
    int find(int i)
    {
        if (!pare.count(i))
        {
            pare[i] = i;
            res++;
        }
        else
        {
            while (i != pare[i])i = pare[i];
        }
        return i;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        res = 0;
        for (const auto& e : edges)
        {
            auto l = find(e[0]);
            auto r = find(e[1]);
            if (l != r)
            {
                pare[l] = r;
                res--;
            }
        }
        return res + n - pare.size();
    }
};