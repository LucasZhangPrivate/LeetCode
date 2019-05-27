/*Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example:



Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
 

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.*/

/*Runtime: 432 ms, faster than 34.30% of C++ online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 67 MB, less than 30.90% of C++ online submissions for Populating Next Right Pointers in Each Node II.*/

//用了queue做的，效果不是很理想
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() {}

Node(int _val, Node* _left, Node* _right, Node* _next) {
val = _val;
left = _left;
right = _right;
next = _next;
}
};
*/
class Solution {
public:
    Node * connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node* pre = q.front();
            q.pop();
            n--;
            while (n-->0)
            {
                if (pre->left)q.push(pre->left);
                if (pre->right)q.push(pre->right);
                Node* cur = q.front();
                q.pop();
                pre->next = cur;
                pre = cur;
            }
            if (pre->left)q.push(pre->left);
            if (pre->right)q.push(pre->right);
        }
        return root;
    }
};

//之前比较巧妙的做法
class Solution {
public:
    Node * connect(Node* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) return root;
        Node* keepRoot = root;
        Node* cur = new Node(-1, nullptr, nullptr);
        Node* keep = cur;
        while (root)
        {
            while (root)
            {
                if (root->left != nullptr)
                {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right != nullptr)
                {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = keep->next;
            keep->next = nullptr;
            if (root)cur = keep;
        }
        return keepRoot;
    }
};