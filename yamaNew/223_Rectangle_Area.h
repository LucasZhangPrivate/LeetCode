/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.*/

/*Runtime: 12 ms, faster than 79.42% of C++ online submissions for Rectangle Area.
Memory Usage: 8.3 MB, less than 13.96% of C++ online submissions for Rectangle Area.*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        signed int xa = max(A, E);
        signed int xb = max(B, F);
        signed int ya = min(C, G);
        signed int yb = min(D, H);
        signed int common = 0;
        if (ya>xa && yb>xb)common = (ya - xa)*(yb - xb);
        signed int res = (C - A)*(D - B) - common + (G - E)*(H - F);
        return res;
    }
};