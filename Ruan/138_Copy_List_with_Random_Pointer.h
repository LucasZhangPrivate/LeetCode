/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

 

Example 1:



Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 

Note:

You must return the copy of the given head as a reference to the cloned list.*/

/*Runtime: 32 ms, faster than 96.00% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 22.2 MB, less than 37.08% of C++ online submissions for Copy List with Random Pointer.*/

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node() {}

Node(int _val, Node* _next, Node* _random) {
val = _val;
next = _next;
random = _random;
}
};
*/
class Solution {
public:
    Node * copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* temp = head;

        while (temp != nullptr)
        {
            Node* second = new Node(-1, nullptr, nullptr);
            second->val = temp->val;
            second->next = temp->next;
            temp->next = second;
            temp = second->next;
        }

        temp = head;
        while (temp != nullptr)
        {
            if (temp->random != nullptr)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node* newHead = head->next;
        temp = head;
        Node* newTemp = head->next;
        while (temp != nullptr)
        {
            temp->next = newTemp->next;
            temp = temp->next;
            if (temp)
            {
                newTemp->next = temp->next;
                newTemp = newTemp->next;
            }
        }
        newTemp->next = nullptr;
        return newHead;
    }
};