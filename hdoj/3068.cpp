#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 110005

int Manacher(char s[],int len)
{
    char t[MAXN * 2];
    int l = 0;
    //��ͷ��'$'��Ϊ�˷�ֹԽ��
    t[l++] = '$';
    t[l++] = '#';
    //��ԭ�ַ�����ͷ��β�Լ��ַ�֮�����һ���ַ�(δ�ڴ��г��ֹ���)
    for(int i = 0; i < len; i++)
    {
        t[l++] = s[i];
        t[l++] = '#';
    }
    t[l++] = '\0';
    //p[i] - 1����t������iΪ�е�Ļ��ĳ���
    vector<int> p(MAXN * 2,0);
    //mx(ĳ���Ĵ����쵽�����ұ��±�),id(mx�������Ĵ������±�)
    int mx = 0,id = 0;
    //bit����������Ĵ������±꣩,maxlen�������ĳ��ȣ�
    int maxlen = 0;
    for(int i = 1; i < l; i++)
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
        }
    }
    return maxlen - 1;
}

int main()
{
    char s[MAXN];
    while(scanf("%s",s) != EOF)
    {
        int len=strlen(s);
        printf("%d\n",Manacher(s,len));
    }
    return 0;
}
