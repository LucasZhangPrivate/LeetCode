/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.*/

/*Runtime: 32 ms, faster than 88.25% of C++ online submissions for Number of Distinct Islands.
Memory Usage: 19 MB, less than 66.99% of C++ online submissions for Number of Distinct Islands.*/

class Solution {
public:
    void help(vector<vector<int>>& grid, int x, int y, int i, int j, vector<pair<int, int>>& mark)
    {
        if (i<0 || j<0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != 1)return;
        grid[i][j] = 0;
        mark.push_back({ i - x,j - y });
        help(grid, x, y, i - 1, j, mark);
        help(grid, x, y, i + 1, j, mark);
        help(grid, x, y, i, j - 1, mark);
        help(grid, x, y, i, j + 1, mark);
    }
    string convert(const vector<pair<int, int>>& mark)
    {
        string res;
        for (const auto& m : mark)
        {
            res += m.first;
            res += m.second;
        }
        return res;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> st;
        for (int i = 0; i< grid.size(); ++i)
        {
            for (int j = 0; j<grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> mark;
                    help(grid, i, j, i, j, mark);
                    /*sort(mark.begin(), mark.end(), [](const auto&l, const auto& r){
                    if(l.first==r.first)return l.second<r.second;
                    return l.first<r.first;
                    });*/

                    st.insert(convert(mark));
                }
            }
        }
        return st.size();
    }
};