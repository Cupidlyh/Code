class Solution {
public:
    bool ion(string s) {//�жϵ�ǰ���������Ƿ�Ϊ1
        string temp = "";
        for(int i = 0; i < s.size() - 1; i++)
            temp += "0";
        temp += "1";
        if(temp == s)
            return false;
        return true;
    }

    int numSteps(string s) {
        int i,res = 0;
        while(ion(s)) {
            res++;
            string snew = "0";//��ֹ������1����ʱ�Ľ�λ
            if(s.at(s.size() - 1) == '0') {//ż��
                s = snew + s.substr(0,s.size() - 1);//����������һλ�����2
            }
            else {//����
                snew += s;
                int bit = 1;//��λ
                for(i = snew.size() - 1; i >= 0; i--) {//���м�1����
                    if(bit == 0)
                        break;
                    else {
                        if(snew.at(i) == '0') {
                            bit = 0;
                            snew.at(i) = '1';
                        }
                        else {
                            snew.at(i) = '0';
                        }
                    }
                }
                if(snew.at(0) == '0')
                    s = snew.substr(1);
                else
                    s = snew;
            }
        }
        return res;
    }
};
