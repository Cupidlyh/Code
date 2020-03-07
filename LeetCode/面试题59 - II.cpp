#include <iostream>

using namespace std;

class MaxQueue {
    queue<int>q;//����
    deque<int>m;//˫����������洢�����е����ֵ
public:
    MaxQueue() {

    }

    int max_value() {
        if(m.empty())
            return -1;
        return m.front();//��ͷ���������ֵ
    }

    void push_back(int value) {
        q.push(value);//Ԫ�ش��q��
        while(!m.empty() && value > m.back())//��ǰԪ�غ�˫�����β���Ƚ�
            m.pop_back();//С�ڵ�ǰԪ�صľ�ɾ��
        m.push_back(value);//���m��β��
    }

    int pop_front() {
        if(q.empty())
            return -1;
        int res = q.front();
        q.pop();
        if(res == m.front())//���������ɾ����Ԫ�ص���˫������е�ͷԪ��
            m.pop_front();//ɾ��
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
