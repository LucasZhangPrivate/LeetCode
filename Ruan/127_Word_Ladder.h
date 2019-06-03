/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.*/

/*Runtime: 72 ms, faster than 87.41% of C++ online submissions for Word Ladder.
Memory Usage: 13 MB, less than 75.32% of C++ online submissions for Word Ladder.*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (!set.count(endWord))return 0;
        queue<string> q;
        q.push(beginWord);
        int i = 1;
        while (!q.empty())
        {
            i++;
            int size = q.size();
            while (size-->0)
            {
                string s = q.front();
                q.pop();
                for (int j = 0; j<s.size(); ++j)
                {
                    auto keep = s[j];
                    for (char a = 'a'; a <= 'z'; ++a)
                    {

                        if (a == keep)continue;
                        s[j] = a;
                        if (s == endWord)return i;
                        else if (set.count(s))
                        {
                            set.erase(s);
                            q.push(s);
                        }
                    }
                    s[j] = keep;
                }


            }
        }
        return 0;

    }
};