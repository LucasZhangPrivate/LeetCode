/*Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.*/

/*Runtime: 104 ms, faster than 57.01% of C++ online submissions for Max Stack.
Memory Usage: 37.2 MB, less than 13.47% of C++ online submissions for Max Stack.*/

class MaxStack {
private:
    stack<int> maxStk;
    stack<int> stk;
public:
    /** initialize your data structure here. */
    MaxStack() {
        maxStk = stack<int>();
        stk = stack<int>();
    }

    void push(int x) {
        if (maxStk.empty() || x >= maxStk.top())maxStk.push(x);
        stk.push(x);
    }

    int pop() {
        int res = stk.top();
        stk.pop();
        if (res == maxStk.top())maxStk.pop();
        return res;
    }

    int top() {
        return stk.top();
    }

    int peekMax() {
        return maxStk.top();
    }

    int popMax() {
        stack<int> temp;
        int res = maxStk.top();
        maxStk.pop();
        while (stk.top() != res)
        {
            temp.push(stk.top());
            stk.pop();
        }
        stk.pop();
        if (!maxStk.empty())
        {
            while (stk.top() != maxStk.top())
            {
                temp.push(stk.top());
                stk.pop();
            }
        }


        while (!temp.empty())
        {
            int cur = temp.top();
            temp.pop();
            stk.push(cur);
            if (maxStk.empty() || cur >= maxStk.top())maxStk.push(cur);
        }
        return res;
    }
};

/**
* Your MaxStack object will be instantiated and called as such:
* MaxStack* obj = new MaxStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->peekMax();
* int param_5 = obj->popMax();
*/