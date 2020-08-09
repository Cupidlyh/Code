class Solution {
public:
    int num(string s) {//���ַ���ת������
        int ans = 0;
        int bit = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            ans += (s[i] - '0') * bit;
            bit *= 10;
        }
        return ans;
    }

    //ͨ���ݹ�����ԭIP��ַ
    //temp��¼�м����ģ�sbit�Ǽ�¼��s�������±꣬ipbit�ǵ�ǰҪ������IP��
    void dfs(string s,string temp,int sbit,int ipbit,vector<string>& res) {
        //���ʣ�µ��ַ�������ʣ�µ�IP�η��䣨ÿ��IP������ռ����һλ�ַ�����������
        if(s.size() - sbit < 4 - ipbit + 1)
            return ;
        //��Ŀ��IP���Ķ����
        if(ipbit > 4) {
            //�ַ���s�ڽ���ǰ�Ķ�IPʱ��������
            if(sbit == s.size())//��������
                res.push_back(temp.substr(0,temp.size() - 1));
            return ;
        }
        //��Ϊ������ΧΪ0-255��i����������ֵ�λ��
        for(int i = 1; i <= 3; i++) {
            string s1 = "";
            if(sbit + i <= s.size()) {
                s1 = s.substr(sbit,i);
                //����ǰ�治����ǰ����
                if(s1[0] == '0' && s1.size() != 1)
                    break;
                int num1 = num(s1);
                if(num1 > 255)
                    break;
            }
            //�ݹ�
            dfs(s,temp + s1 + ".",sbit + i,ipbit + 1,res);
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() > 12 || s.size() < 4)
            return res;
        dfs(s,"",0,1,res);
        return res;
    }
};
