class CQueue {
public:
    stack<int> sa;//插入栈
    stack<int> ta;//删除栈
    CQueue() {

    }

    void appendTail(int value) {
        sa.push(value);//元素直接插入到插入栈
    }

    int deleteHead() {
        if(ta.empty()) {//删除栈为空
            while(!sa.empty()) {//将插入栈元素存进删除栈
                int temp = sa.top();
                sa.pop();
                ta.push(temp);
            }
        }
        if(ta.empty())
            return -1;
        int res = ta.top();
        ta.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
