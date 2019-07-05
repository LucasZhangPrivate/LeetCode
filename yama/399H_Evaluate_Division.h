/*Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.*/

/*Runtime: 4 ms, faster than 82.87% of C++ online submissions for Evaluate Division.
Memory Usage: 9.2 MB, less than 91.41% of C++ online submissions for Evaluate Division.*/

class Solution {
public:
    double divide(string A, string B, unordered_map<string, unordered_map<string, double>>& mp, unordered_set<string>& visited)
    {
        if (A == B) return 1.0;
        visited.insert(A);
        for (const auto& p : mp[A])
        {
            string C = p.first;
            if (visited.count(C))continue;
            double d = divide(C, B, mp, visited);
            if (d>0)return d * mp[A][C];
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        for (int i = 0; i<equations.size(); ++i)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double v = values[i];
            mp[A][B] = v;
            mp[B][A] = 1 / v;
        }
        vector<double> res;
        for (const auto& q : queries)
        {
            string A = q[0];
            string B = q[1];
            if (!mp.count(A) || !mp.count(B))
            {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            res.push_back(divide(A, B, mp, visited));
        }
        return res;
    }
};