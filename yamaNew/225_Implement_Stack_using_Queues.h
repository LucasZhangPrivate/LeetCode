/*Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).*/

/*Runtime: 4 ms, faster than 75.45% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 8.8 MB, less than 40.48% of C++ online submissions for Implement Stack using Queues.*/

class MyStack {
private:
    queue<int>* a;
    queue<int>* b;
public:
    /** Initialize your data structure here. */
    MyStack() {
        a = new queue<int>();
        b = new queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        auto cur = a->empty() ? b : a;
        cur->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto cur = a->empty() ? b : a;
        auto next = a->empty() ? a : b;
        while (cur->size()>1)
        {
            auto n = cur->front();
            cur->pop();
            next->push(n);
        }
        auto res = cur->front();
        cur->pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        auto cur = a->empty() ? b : a;
        auto next = a->empty() ? a : b;
        int res = 0;
        while (cur->size()>0)
        {
            if (cur->size() == 1)res = cur->front();
            auto n = cur->front();
            cur->pop();
            next->push(n);
        }
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return a->empty() && b->empty();
    }
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/