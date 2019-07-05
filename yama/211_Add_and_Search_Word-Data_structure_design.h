/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.*/

/*Runtime: 148 ms, faster than 32.48% of C++ online submissions for Add and Search Word - Data structure design.
Memory Usage: 80.8 MB, less than 27.26% of C++ online submissions for Add and Search Word - Data structure design.*/

struct TrieNode {
    vector<TrieNode*> next;
    bool last;
    TrieNode()
    {
        last = false;
        next = vector<TrieNode*>(26, nullptr);
    }
};

class WordDictionary {
private:
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto node = root;
        for (const auto& c : word)
        {
            int i = c - 'a';
            if (node->next[i] == nullptr)
            {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->last = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool help(TrieNode* root, string word)
    {
        if (word.empty())
        {
            return root->last;
        }
        auto c = word[0];
        if (c == '.')
        {
            bool mark = false;
            for (auto n : root->next)
            {
                if (n != nullptr)
                {
                    mark |= help(n, word.substr(1));
                }
            }
            return mark;
        }
        else
        {
            if (root->next[c - 'a'] == nullptr) return false;
            else return help(root->next[c - 'a'], word.substr(1));
        }
    }
    bool search(string word) {
        auto node = root;
        return help(root, word);
    }
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/