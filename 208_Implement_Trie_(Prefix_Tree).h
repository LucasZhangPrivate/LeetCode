/*Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.*/

/*Runtime: 72 ms, faster than 93.95% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 48.3 MB, less than 17.11% of C++ online submissions for Implement Trie (Prefix Tree).*/

struct Node {
    vector<Node*> nodes;
    bool isEnd;
    Node() {
        isEnd = false;
        nodes = vector<Node*>(26, nullptr);
    }
};


class Trie {
public:
    Node * head;
    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = head;
        for (const auto& c : word)
        {
            if (node->nodes[c - 'a'] == nullptr)
            {
                node->nodes[c - 'a'] = new Node();
            }
            node = node->nodes[c - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = head;
        for (const auto& c : word)
        {
            if (node->nodes[c - 'a'] == nullptr)return false;
            else node = node->nodes[c - 'a'];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = head;
        for (const auto& c : prefix)
        {
            if (node->nodes[c - 'a'] == nullptr)return false;
            else node = node->nodes[c - 'a'];
        }
        return true;
    }
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/