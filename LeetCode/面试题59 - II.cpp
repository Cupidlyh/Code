#include <iostream>

using namespace std;

class MaxQueue {
    queue<int>q;//队列
    deque<int>m;//双向队列用来存储队列中的最大值
public:
    MaxQueue() {

    }

    int max_value() {
        if(m.empty())
            return -1;
        return m.front();//从头部返回最大值
    }

    void push_back(int value) {
        q.push(value);//元素存进q中
        while(!m.empty() && value > m.back())//当前元素和双向队列尾部比较
            m.pop_back();//小于当前元素的就删除
        m.push_back(value);//存进m的尾部
    }

    int pop_front() {
        if(q.empty())
            return -1;
        int res = q.front();
        q.pop();
        if(res == m.front())//如果队列中删除的元素等于双向队列中的头元素
            m.pop_front();//删除
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
