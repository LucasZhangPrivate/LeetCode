/*There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.*/

/*Runtime: 24 ms, faster than 62.66% of C++ online submissions for Friend Circles.
Memory Usage: 10.8 MB, less than 93.66% of C++ online submissions for Friend Circles.*/

class Solution {
public:
    int find(const vector<int>& v, int i)
    {
        while (i != v[i])i = v[i];
        return i;
    }
    void combine(vector<int>& v, int i, int j)
    {
        auto a = find(v, i);
        auto b = find(v, j);
        if (a != b)
        {
            v[a] = b;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> v(M.size(), 0);
        for (int i = 0; i<v.size(); ++i)v[i] = i;
        for (int i = 0; i<M.size(); ++i)
        {
            for (int j = 0; j<M[i].size(); ++j)
            {
                if (M[i][j] == 1 && i != j)
                {
                    combine(v, i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i< v.size(); ++i)
        {
            if (v[i] == i)res++;
        }
        return res;
    }
};