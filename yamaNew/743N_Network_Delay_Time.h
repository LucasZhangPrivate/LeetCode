/*There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.*/

/*Runtime: 152 ms, faster than 24.50% of C++ online submissions for Network Delay Time.
Memory Usage: 24 MB, less than 98.26% of C++ online submissions for Network Delay Time.*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        constexpr const int m = (100 - 1) * 100;
        vector<int> dis(N, m);
        dis[K - 1] = 0;
        for (int i = 0; i< N; ++i)
        {
            for (const auto& t : times)
            {
                int u = t[0] - 1;
                int v = t[1] - 1;
                int w = t[2];
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
        auto res = *max_element(dis.begin(), dis.end());
        return res == m ? -1 : res;
    }
};