/*An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.*/

/*Runtime: 24 ms, faster than 100.00% of C++ online submissions for Flood Fill.
Memory Usage: 10.2 MB, less than 99.22% of C++ online submissions for Flood Fill.*/

class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int newColor, int old)
    {
        if (i<0 || i >= image.size() || j<0 || j >= image[0].size() || image[i][j] == newColor ||
            image[i][j] != old)return;
        image[i][j] = newColor;
        fill(image, i - 1, j, newColor, old);
        fill(image, i + 1, j, newColor, old);
        fill(image, i, j - 1, newColor, old);
        fill(image, i, j + 1, newColor, old);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old = image[sr][sc];
        fill(image, sr, sc, newColor, old);
        return image;
    }
};