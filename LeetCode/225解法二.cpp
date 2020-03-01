#include <iostream>

using namespace std;

class MyStack {
    queue<int>q_s;//队列
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q_s.push(x);//将元素存进队列中
        int i;
        for(i = 1; i <= q_s.size() - 1; i++) {//将前q_s.size() - 1个元素重新存进队列中
            q_s.push(q_s.front());
            q_s.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q_s.front();
        q_s.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return q_s.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q_s.empty();
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
