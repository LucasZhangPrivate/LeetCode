/*You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example:

Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
 

Explanation for the above example:

Given the following multilevel doubly linked list:


 

We should return the following flattened doubly linked list:

*/

/*Runtime: 96 ms, faster than 81.30% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
Memory Usage: 31.2 MB, less than 9.92% of C++ online submissions for Flatten a Multilevel Doubly Linked List.*/

/*
// Definition for a Node.
class Node {
public:
int val;
Node* prev;
Node* next;
Node* child;

Node() {}

Node(int _val, Node* _prev, Node* _next, Node* _child) {
val = _val;
prev = _prev;
next = _next;
child = _child;
}
};
*/

//√≤À∆∏„∏¥‘”¡À µ›πÈ
class Solution {
public:
    vector<Node*> fl(Node* head)
    {
        auto cur = head;
        auto pre = head;
        Node* next = nullptr;
        while (cur)
        {
            next = cur->next;
            if (cur->child != nullptr)
            {
                if (next == nullptr)
                {
                    auto p = fl(cur->child);
                    cur->child = nullptr;
                    cur->next = p[0];
                    p[0]->prev = cur;
                    return { head,p[1] };
                }
                else
                {
                    auto p = fl(cur->child);
                    cur->next = p[0];
                    p[0]->prev = cur;
                    cur->child = nullptr;
                    p[1]->next = next;
                    next->prev = p[1];
                }
            }
            pre = cur;
            cur = next;
        }
        return { head, pre };
    }
    Node* flatten(Node* head) {
        if (head == nullptr) return head;
        Node* cur = head;
        fl(cur);
        return head;
    }
};

/*Runtime: 104 ms, faster than 45.76% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
Memory Usage: 30.8 MB, less than 90.90% of C++ online submissions for Flatten a Multilevel Doubly Linked List.*/

//ºÚµ•∞Ê µ¸¥˙
class Solution {
public:
    Node * flatten(Node* head) {
        Node* cur = head;
        while (cur)
        {
            if (cur->child == nullptr) cur = cur->next;
            else
            {
                Node* child = cur->child;
                while (child->next)child = child->next;
                child->next = cur->next;
                if (cur->next)cur->next->prev = child;
                child = cur->child;
                cur->child = nullptr;
                cur->next = child;
                child->prev = cur;
                cur = child;
            }
        }
        return head;
    }
};