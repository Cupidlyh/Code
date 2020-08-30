class Solution {
public:
    /*
    * ��������Ӵ�
    */
    int Manacher(string &s)//�������㷨
    {
        //��ͷ��'$'��Ϊ�˷�ֹԽ��
        string t = "$#";
        //��ԭ�ַ�����ͷ��β�Լ��ַ�֮�����һ���ַ�(δ�ڴ��г��ֹ���)
        for(int i = 0; i < s.length(); i++)
        {
            t += s[i];
            t += '#';
        }
        //p[i] - 1����t������iΪ�е�Ļ��ĳ���
        vector<int> p(t.length(),0);
        //mx(ĳ���Ĵ����쵽�����ұ��±�),id(mx�������Ĵ������±�)
        int mx = 0,id = 0;
        //bit����������Ĵ������±꣩,maxlen�������ĳ��ȣ�
        int bit,maxlen = 0;
        int ans = 0;//����Ӵ���
        for(int i = 1; i < t.length(); i++)
        {
            //�㷨����
            p[i] = mx > i ? min(p[2 * id - i],mx - i) : 1;
            //һ�������бȽ�
            //t��������� = '$',���ұ� = '\0'�������жϱ߽�
            while(t[i + p[i]] == t[i - p[i]])
                p[i]++;
            //��t[i]ƥ��� �ұ߽糬��mxʱ,mx��id�͸���
            if(i + p[i] > mx)
            {
                mx = i + p[i];
                id = i;
            }
            //���½������
            if(p[i] > maxlen)
            {
                maxlen = p[i];
                bit = i;
            }
            ans += (p[i] / 2);//����Ӵ���
        }
        //return s.substr((bit - maxlen) / 2,maxlen - 1);
        //return maxlen - 1;
        return ans;//����Ӵ���
    }

    int countSubstrings(string s) {
        return Manacher(s);
    }
};
