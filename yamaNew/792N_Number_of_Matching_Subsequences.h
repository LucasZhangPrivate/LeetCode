/*Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].*/

/*Runtime: 208 ms, faster than 63.88% of C++ online submissions for Number of Matching Subsequences.
Memory Usage: 44.2 MB, less than 29.63% of C++ online submissions for Number of Matching Subsequences.*/

class Solution {
public:
    int numMatchingSubseq(const string& S, vector<string>& words) {
        vector<vector<int>> pos(128);
        for (int i = 0; i < S.length(); ++i)
            pos[S[i]].push_back(i);
        int ans = 0;
        for (const string& word : words)
            ans += isMatch(word, pos);
        return ans;
    }

private:
    unordered_map<string, bool> m_;
    bool isMatch(const string& word, const vector<vector<int>>& pos) {
        if (m_.count(word)) return m_[word];
        int last_index = -1;
        for (const char c : word) {
            const vector<int>& p = pos[c];
            const auto it = std::lower_bound(p.begin(), p.end(), last_index + 1);
            if (it == p.end()) return m_[word] = false;
            last_index = *it;
        }
        return m_[word] = true;
    }
};