/*Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.*/

/*Runtime: 76 ms, faster than 95.70% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
Memory Usage: 27.4 MB, less than 38.58% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.*/

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
//别人的答案，感觉这个很不错
class Solution {
public:
    Node * treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        Node*  left = treeToDoublyList(root->left);
        Node* right = treeToDoublyList(root->right);
        Node* newLeft = left == nullptr ? root : left;
        Node* newRight = right == nullptr ? root : right->left;
        Node* leftMid = left == nullptr ? nullptr : left->left;
        Node* rightMid = right == nullptr ? nullptr : right;

        if (leftMid != nullptr)
        {
            root->left = leftMid;
            leftMid->right = root;
        }
        if (rightMid != nullptr)
        {
            root->right = rightMid;
            rightMid->left = root;
        }
        newLeft->left = newRight;
        newRight->right = newLeft;
        return newLeft;

    }
};