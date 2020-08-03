class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";//�洢���
        //�ӷ������Ǵ��������ֵ�β����ʼ���
        int i = num1.length() - 1;//num1��β��
        int j = num2.length() - 1;//num2��β��
        int carry = 0;//��λ
        while(i >= 0 || j >= 0) {
            //�洢num1,num2��ǰλ������
            int num11 = 0,num22 = 0;
            if(i >= 0) {
                num11 = num1[i--] - '0';
            }
            if(j >= 0) {
                num22 = num2[j--] - '0';
            }
            int sum = 0;
            //��¼��ǰλ�ĺ�
            sum = (num11 + num22 + carry) % 10;
            res += sum + '0';//���ͼӵ������
            //�����λ
            carry = (num11 + num22 + carry) / 10;
        }
        //������н�λ��Ϣ���ӵ������
        if(carry != 0)
            res += carry + '0';
        //��ת�ַ�����Ϊnum1 + num2�Ľ��
        reverse(res.begin(), res.end());
        return res;
    }
};
