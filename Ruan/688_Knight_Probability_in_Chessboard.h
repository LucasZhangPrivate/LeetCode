/*On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

 



 

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

 

Example:

Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.*/

//别人的算法用的dp，能符合要求，我用的递归，超时
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double Prob[N][N] = {};
        double Next[N][N] = {};
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++)
            {
                Prob[r][c] = 1;

            }
        }
        if (K == 0) return Prob[r][c];
        for (int i = 1; i <= K; i++) {
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    Next[r][c] = 0;
                    Next[r][c] += (r + 2 <= N - 1 && r + 2 >= 0 && c + 1 <= N - 1 && c + 1 >= 0) ? 0.125 * Prob[r + 2][c + 1] : 0;
                    Next[r][c] += (r - 2 <= N - 1 && r - 2 >= 0 && c + 1 <= N - 1 && c + 1 >= 0) ? 0.125 * Prob[r - 2][c + 1] : 0;
                    Next[r][c] += (r + 2 <= N - 1 && r + 2 >= 0 && c - 1 <= N - 1 && c - 1 >= 0) ? 0.125 * Prob[r + 2][c - 1] : 0;
                    Next[r][c] += (r - 2 <= N - 1 && r - 2 >= 0 && c - 1 <= N - 1 && c - 1 >= 0) ? 0.125 * Prob[r - 2][c - 1] : 0;
                    Next[r][c] += (r + 1 <= N - 1 && r + 1 >= 0 && c + 2 <= N - 1 && c + 2 >= 0) ? 0.125 * Prob[r + 1][c + 2] : 0;
                    Next[r][c] += (r - 1 <= N - 1 && r - 1 >= 0 && c + 2 <= N - 1 && c + 2 >= 0) ? 0.125 * Prob[r - 1][c + 2] : 0;
                    Next[r][c] += (r + 1 <= N - 1 && r + 1 >= 0 && c - 2 <= N - 1 && c - 2 >= 0) ? 0.125 * Prob[r + 1][c - 2] : 0;
                    Next[r][c] += (r - 1 <= N - 1 && r - 1 >= 0 && c - 2 <= N - 1 && c - 2 >= 0) ? 0.125 * Prob[r - 1][c - 2] : 0;
                }
            }
            if (i < K) {
                for (int r = 0; r < N; r++) {
                    for (int c = 0; c < N; c++) {
                        Prob[r][c] = Next[r][c];
                    }
                }
            }
        }
        return Next[r][c];
    }
};

//我的超时递归
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (r<0 || r >= N || c<0 || c >= N)return 0.0;
        if (K == 0)return 1;
        double result = 0;
        result += 0.125*knightProbability(N, K - 1, r - 2, c - 1);
        result += 0.125*knightProbability(N, K - 1, r - 2, c + 1);
        result += 0.125*knightProbability(N, K - 1, r - 1, c - 2);
        result += 0.125*knightProbability(N, K - 1, r - 1, c + 2);
        result += 0.125*knightProbability(N, K - 1, r + 2, c - 1);
        result += 0.125*knightProbability(N, K - 1, r + 2, c + 1);
        result += 0.125*knightProbability(N, K - 1, r + 1, c - 2);
        result += 0.125*knightProbability(N, K - 1, r + 1, c + 2);
        return result;
    }
};