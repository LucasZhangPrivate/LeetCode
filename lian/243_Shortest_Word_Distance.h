/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = ��coding��, word2 = ��practice��
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/

/*Runtime: 16 ms, faster than 92.67% of C++ online submissions for Shortest Word Distance.
Memory Usage: 11.9 MB, less than 20.24% of C++ online submissions for Shortest Word Distance.*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dis = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i<words.size(); ++i)
        {
            if (words[i] == word1)a = i;
            if (words[i] == word2)b = i;
            if (a != -1 && b != -1)
            {
                dis = min(dis, abs(a - b));
            }
        }
        return dis;
    }
};