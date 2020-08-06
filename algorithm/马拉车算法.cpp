#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

/*
* ��������Ӵ�
*/
string Manacher(string &s)
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
    }
    return s.substr((bit - maxlen) / 2,maxlen - 1);
    //return maxlen - 1;
}
/*
* abaaba
* i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
* t[i]:  $ # a # b # a # a # b  #  a  #
* p[i]:  1 1 2 1 4 1 2 7 2 1 4  1  2  1
*/
int main()
{
    string s;
    s.resize(1000);//������������ģ
    while(scanf("%s",&s[0]) != EOF)
    {
        Manacher(s);
    }
    return 0;
}
