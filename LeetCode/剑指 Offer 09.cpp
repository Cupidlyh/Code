class CQueue {
public:
    stack<int> sa;//����ջ
    stack<int> ta;//ɾ��ջ
    CQueue() {

    }

    void appendTail(int value) {
        sa.push(value);//Ԫ��ֱ�Ӳ��뵽����ջ
    }

    int deleteHead() {
        if(ta.empty()) {//ɾ��ջΪ��
            while(!sa.empty()) {//������ջԪ�ش��ɾ��ջ
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
