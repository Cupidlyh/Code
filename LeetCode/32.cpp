class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> left;
        //�ȼ���-1��Ϊ�˱���һ��ʼ��������ʱ��û�����һ��û��ƥ��������ŵ��±�
        left.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {//����������
                left.push(i);//�±����ջ��
            }
            else {//����������
                left.pop();//���������Ŵ���ƥ����������
                if(left.empty()) {//ջΪ��
                    left.push(i);//�����±�������һ��û��ƥ��������ŵ��±�
                    continue;
                }
                //ջ��Ϊ�գ���ǰ�����ŵ��±��ȥջ��Ԫ�ؼ�Ϊ�Ը�������Ϊ��β�����Ч���ŵĳ���
                res = max(res,i - left.top());
            }
        }
        return res;
    }
};
