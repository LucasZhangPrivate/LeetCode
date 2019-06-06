/*There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 
Follow up:
Could you solve it in O(nk) runtime?*/

/*Runtime: 12 ms, faster than 97.75% of C++ online submissions for Paint House II.
Memory Usage: 10.2 MB, less than 80.88% of C++ online submissions for Paint House II.*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0)return 0;
        int n = costs.size();
        for (int i = 1; i < n; ++i)
        {
            for (int k = 0; k < costs[i].size(); ++k)
            {
                int min = INT_MAX;
                for (int j = 0; j< costs[i - 1].size(); ++j)
                {
                    if (j == k)continue;
                    if (costs[i - 1][j] < min)min = costs[i - 1][j];
                }
                costs[i][k] = min + costs[i][k];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i<costs[n - 1].size(); ++i)
        {
            res = min(res, costs[n - 1][i]);
        }
        return res;
    }
};

/*Runtime: 8 ms, faster than 99.68% of C++ online submissions for Paint House II.
Memory Usage: 10.2 MB, less than 70.10% of C++ online submissions for Paint House II.*/
//O£¨nk£©
class Solution {
public:
    void help(vector<int>& in)
    {
        int a = INT_MAX;
        int b = a;
        for (const auto& i : in)
        {
            if (i< a)
            {
                b = a;
                a = i;
            }
            else if (i<b)
            {
                b = i;
            }
        }
        for (int i = 0; i< in.size(); ++i)
        {
            if (a == b)in[i] = a;
            else if (in[i] != a) in[i] = a;
            else in[i] = b;
        }
    }
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0)return 0;
        int n = costs.size();
        for (int i = 1; i < n; ++i)
        {
            help(costs[i - 1]);
            for (int k = 0; k < costs[i].size(); ++k)
            {

                costs[i][k] += costs[i - 1][k];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i<costs[n - 1].size(); ++i)
        {
            res = min(res, costs[n - 1][i]);
        }
        return res;
    }
};