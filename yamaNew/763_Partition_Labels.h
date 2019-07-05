/*A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.*/

/*Runtime: 12 ms, faster than 30.63% of C++ online submissions for Partition Labels.
Memory Usage: 8.7 MB, less than 76.91% of C++ online submissions for Partition Labels.*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.size() == 1)return { 1 };
        int i = 0;
        int pre = 0;
        int far = -1;
        vector<int> res;
        while (true)
        {
            pre = far + 1;
            auto keep = pre;
            while (true)
            {
                int temp = S.find_last_of(S[pre]);
                far = max(far, temp);
                if (far == pre) break;
                pre++;
            }
            res.push_back(far - keep + 1);
            if (far == S.size() - 1)break;
        }
        return res;
    }
};

/*Runtime: 4 ms, faster than 97.35% of C++ online submissions for Partition Labels.
Memory Usage: 8.8 MB, less than 69.13% of C++ online submissions for Partition Labels.*/
//一年前做的，思路差不多，但是實現不一樣，效率高很多
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> mymap(26, 0);
        vector<int> result;
        for (int i = 0; i<S.size(); ++i)
        {
            mymap[S[i] - 'a'] = i;
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i<S.size() && start<S.size(); ++i)
        {
            end = max(end, mymap[S[i] - 'a']);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};