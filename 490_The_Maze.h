/*There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

 */

/*Runtime: 32 ms, faster than 97.30% of C++ online submissions for The Maze.
Memory Usage: 30.1 MB, less than 14.52% of C++ online submissions for The Maze.*/

class Solution {
public:
    bool search(vector<vector<int>>& maze, vector<int> cur, vector<int>& destination, vector<vector<bool>>& visited)
    {
        int i = cur[0], j = cur[1];
        bool result = false;
        if (i == destination[0] && j == destination[1])return true;
        visited[i][j] = true;
        int up = i;
        while (up - 1 >= 0 && maze[up - 1][j] == 0)up--;
        if (up != i && !visited[up][j]) result = result || search(maze, { up, j }, destination, visited);
        int down = i;
        while (down + 1<maze.size() && maze[down + 1][j] == 0)down++;
        if (down != i && !visited[down][j])result = result || search(maze, { down,j }, destination, visited);
        int left = j;
        while (left - 1 >= 0 && maze[i][left - 1] == 0) left--; //开始不够细心，将maze[i][left - 1]错写成maze[i][j - 1]，debug半天才找到原因，注意细心！
        if (left != j && !visited[i][left])result = result || search(maze, { i,left }, destination, visited);
        int right = j;
        while (right + 1<maze[i].size() && maze[i][right + 1] == 0)right++;
        if (right != j && !visited[i][right])result = result || search(maze, { i,right }, destination, visited);
        return result;
    }


    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int i = maze.size();
        int j = maze[0].size();
        vector<bool> n(j, false);
        vector<vector<bool>> visited;
        while (i-->0) visited.push_back(n);
        return search(maze, start, destination, visited);
    }
};