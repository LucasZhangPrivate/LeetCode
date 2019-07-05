/*Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.*/

/*Runtime: 44 ms, faster than 90.84% of C++ online submissions for Design Linked List.
Memory Usage: 19.5 MB, less than 39.72% of C++ online submissions for Design Linked List.*/

struct Node
{
    Node* next;
    int val;
    Node(int _val) :val(_val) { next = nullptr; };
};
class MyLinkedList {
private:
    Node * head;
    Node* tail;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = nullptr;
        len = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= len)return -1;
        else
        {
            auto node = head;
            while (index-->0)node = node->next;
            return node->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (head == nullptr)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node* pre = new Node(val);
            pre->next = head;
            head = pre;
        }
        len++;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (tail == nullptr)
        {
            tail = new Node(val);
            head = tail;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        len++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index> len) return;
        else if (index == len)
        {
            addAtTail(val);
        }
        else if (index <= 0) // assume less than 0 valid
        {
            addAtHead(val);
        }
        else
        {
            auto pre = head;
            while (index-->1)pre = pre->next;
            auto keep = pre->next;
            pre->next = new Node(val);
            pre->next->next = keep;
            len++;  //注意len++在这里面，因为addhead和tail里包含着len++
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int keep = index;
        if (index >= len || index<0)return;
        else
        {
            Node* pre = new Node(-1);
            pre->next = head;
            while (index-->0)pre = pre->next;
            auto de = pre->next;
            pre->next = pre->next->next;
            delete(de);

            if (keep == 0)head = pre->next;
            if (keep == len - 1)tail = pre;
        }

        len--;
    }
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/