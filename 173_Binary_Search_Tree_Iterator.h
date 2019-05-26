/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.*/

/*Runtime: 60 ms, faster than 87.80% of C++ online submissions for Binary Search Tree Iterator.
Memory Usage: 24.3 MB, less than 72.45% of C++ online submissions for Binary Search Tree Iterator.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
private:
    stack<TreeNode*> stk;

    void pushLeft(TreeNode* root)
    {
        if (root)
        {
            stk.push(root);
            pushLeft(root->left);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    /** @return the next smallest number */
    int next() {
        auto res = stk.top();
        stk.pop();
        pushLeft(res->right);
        return res->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/