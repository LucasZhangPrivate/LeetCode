/*Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.*/

/*Runtime: 8 ms, faster than 97.83% of C++ online submissions for Most Common Word.
Memory Usage: 9.2 MB, less than 84.40% of C++ online submissions for Most Common Word.*/

class Solution {
public:
    string toLow(string in)
    {
        for (auto& i : in)
        {
            i = tolower(i);
        }
        return in;
    }
    bool isLetter(char c)
    {
        return c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z';
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        string cur;
        int count = 0;
        unordered_set<string> s(banned.begin(), banned.end());
        auto j = 0;
        while (j <paragraph.size())
        {
            while (j<paragraph.size() && !isLetter(paragraph[j]))++j;
            string str;
            while (j<paragraph.size() && isLetter(paragraph[j]))
            {
                str += paragraph[j++];
            }
            if (!str.empty())
            {
                str = toLow(str);
                if (!s.count(str))
                {
                    m[str]++;
                    if (count<m[str])
                    {
                        count = m[str];
                        cur = str;
                    }
                }
            }
        }
        return cur;
    }
};