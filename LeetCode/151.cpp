class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int len = s.length(),left,right;
        for(left = 0; left < len; left++)//ȥ���ײ��ո�
            if(s[left] != ' ')
                break;
        int num = 0;//��¼������
        int i = len;
        while(i >= left)
        {
            for(i = i - 1; i >= left; i--)//ȥ�ո�
                if(s[i] != ' ')
                    break;
            right = i;//right��¼��ǰ������ʵ�β��
            for(; i >= left; i--)//�ҵ��ʵĳ��ȣ���ǰ���ʵ�ͷ����
                if(s[i] == ' ')
                    break;
            if(num == 0) {//�׸���ȥ�ĵ���ǰ�治��Ҫ�ո�
                num++;
                ans += s.substr(i + 1,right - i);//��ȡ���ʼӵ������
            }
            else {//�ڶ������ʿ�ʼǰ��Ҫ�ӿո����
                ans += " ";
                ans += s.substr(i + 1,right - i);//��ȡ���ʼӵ������
            }
        }
        return ans;
    }
};
