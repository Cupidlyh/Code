class Solution {
public:
    //sb��ʾs���±꣬pb��ʾp���±�
    bool match(string& s,int sb,string& p,int pb) {
        if(pb >= p.length())//���򴮳��������жϴ�ƥ���ַ����Ƿ�Ҳ��������
            return sb >= s.length();
        bool curr = sb < s.length() && ((s[sb] == p[pb]) || (p[pb] == '.'));//�жϵ�ǰ�±��Ƿ����ƥ��
        if(pb + 1 < p.length() && p[pb + 1] == '*') {//'*' ƥ���������ǰ�����һ��Ԫ��
            //ƥ��0��������Ҫ�±��ƶ���λ����ƥ���ַ����±겻�ƶ�����Ϊ������ƥ��������Ե�ǰԪ���ж��Ƿ���Զ�Ӧ������ν�ģ�
            //ƥ���������±겻�ƶ�����ƥ���ַ����±��ƶ�һλ
            return match(s,sb,p,pb + 2) || (curr && match(s,sb + 1,p,pb));
        }
        else {//û����'.'��'*'�����ж϶��ߵ���һ���±�
            return curr && match(s,sb + 1,p,pb + 1);
        }
    }

    bool isMatch(string s, string p) {
        return match(s,0,p,0);
    }
};
