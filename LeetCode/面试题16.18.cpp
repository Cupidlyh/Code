class Solution {
public:
    bool patternMatching(string pattern, string value) {
        //���������
        //1.patternΪ��
        if(pattern.empty())
            return value.empty();
        //2.pattern��Ϊ��
        //2.1��valueΪ�գ��ж�pattern�Ƿ�ֻ��һ����ĸ���
        if(value.empty()) {
            int i;
            for(i = 1; i < pattern.length(); i++) {
                if(pattern[0] != pattern[i])
                    return false;
            }
            if(i == pattern.length())
                return true;
        }
        //2.2pattern��Ϊ�գ�value��Ϊ��
        int a = 0,b = 0;//�洢pattern��a��b������
        for(int i = 0; i < pattern.length(); i++) {
            if(pattern[i] == 'a')
                a++;
            else
                b++;
        }
        //�ж�pattern��ֻ����һ����ĸ�����
        if(a == 0)//ֻ����b
            return check1(value,b);
        if(b == 0)//ֻ����a
            return check1(value,a);
        //2.2.1 a��b�����֣�����������һ��Ϊ���ַ���
        if(check1(value,a))//bΪ�մ�ʱ
            return true;
        if(check1(value,b))//aΪ�մ�ʱ
            return true;
        //2.2.2 a��b����Ϊ�գ�ö��a��b���ȣ�ö��a�ĳ��Ⱦ���Ψһ��ȷ��b�ĳ���
        for(int lena = 1; lena * a <= value.length() - b; lena++) {//b�ĳ�������Ϊ1����Ϊ�޶�����
            if((value.length() - lena * a) % b != 0)
                continue;
            int lenb = (value.length() - lena * a) / b;
            if(check2(pattern,value,lena,lenb))
                return true;
        }
        return false;
    }

    bool check1(string& value,int& k) {//�ж�value�ַ����ܷ����÷�k��
        if(value.length() % k != 0)
            return false;
        int cnt = value.length() / k;
        for(int i = cnt; i < value.length(); i += cnt) {
            if(value.substr(i,cnt) != value.substr(0,cnt))//ÿ�ε��ַ�������ͬ
                return false;
        }
        return true;
    }

    bool check2(string& pattern,string& value,int& lena,int& lenb) {//����a��bƥ����ַ����ĳ��Ƚ��зָ�����ж�
        string sa = "",sb = "";//����a��b��Ӧ���ַ���
        for(int i = 0,j = 0; i < pattern.length(); i++) {//iָ����ָpattern���±꣬jָ����ָvalue���±�
            if(pattern[i] == 'a') {
                if(sa == "") {//�մ�ʱ��Ҫ��ֵ
                    sa = value.substr(j,lena);
                }
                else {//�Ƚ�
                    if(sa != value.substr(j,lena))
                        return false;
                }
                j += lena;
            }
            else {
                if(sb == "") {//�մ�ʱ��Ҫ��ֵ
                    sb = value.substr(j,lenb);
                }
                else {//�Ƚ�
                    if(sb != value.substr(j,lenb))
                        return false;
                }
                j += lenb;
            }
        }
        return sa != sb;//a��b��ƥ����ַ���������ͬ
    }
};
