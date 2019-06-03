/*Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.*/

/*Runtime: 28 ms, faster than 99.80% of C++ online submissions for Serialize and Deserialize BST.
Memory Usage: 29.3 MB, less than 21.97% of C++ online submissions for Serialize and Deserialize BST.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "#,";
        else
        {
            return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        }
    }

    TreeNode* dese(queue<string>& q)
    {
        if (q.front() == "#")
        {
            q.pop();
            return nullptr;
        }
        else
        {
            auto cur = new TreeNode(stoi(q.front()));
            q.pop();
            cur->left = dese(q);
            cur->right = dese(q);
            return cur;
        }
    }

    queue<string> parse(const string& data)
    {
        queue<string> q;
        int i = 0;
        while (i<data.size())
        {
            auto j = data.find_first_of(',', i);
            q.push(data.substr(i, j - i));
            i = j + 1;
        }
        return q;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = parse(data);
        return dese(q);
    }
};

//不用queue，直接用string做，最后一个case超内存

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "#,";
        else
        {
            return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        }
    }

    TreeNode* dese(string& data)
    {
        if (data[0] == '#')
        {
            data = data.substr(2);
            return nullptr;
        }
        else
        {
            auto i = data.find_first_of(',');
            string s = data.substr(0, i);
            int n = stoi(s);
            data = data.substr(i + 1);
            TreeNode* cur = new TreeNode(n);
            cur->left = dese(data);
            cur->right = dese(data);
            return cur;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dese(data);
    }
};
