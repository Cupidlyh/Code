class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int>s;//ջ
        vector<int> res(T.size(),0);//���
        int temp = T.size() - 1;
        for(int i = T.size() - 1; i >= 0; i--) {
            if(!s.empty())
                temp = s.top();
            while(!s.empty() && T[temp] <= T[i]) {//��ջ��Ԫ�رȽ�
                s.pop();
                if(!s.empty())
                    temp = s.top();
            }
            if(T[temp] > T[i]) {
                res[i] = temp - i;
            }
            s.push(i);
        }
        return res;
    }
};
