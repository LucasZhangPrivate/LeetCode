/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.*/

/*Runtime: 32 ms, faster than 92.58% of C++ online submissions for Min Stack.
Memory Usage: 16.9 MB, less than 76.23% of C++ online submissions for Min Stack.*/

class MinStack {
private:
    stack<int> mstk;
    stack<int> stk;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (mstk.empty() || mstk.top() >= x)
        {
            mstk.push(x);
        }
        stk.push(x);

    }

    void pop() {
        if (mstk.top() == stk.top())
        {
            mstk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mstk.top();
    }
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/