#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int T;
    string s;
    int book[26];
    scanf("%d",&T);
    while(T--)
    {
        memset(book,0,sizeof(book));
        cin>>s;
        string res,temp;
        int flag = 0,i,j;
        int len = s.length();
        for(i = 0; i < len; i++)//ͳ��AGCT�ĸ���ĸ���ִ���
            book[s[i] - 'A']++;
        for(i = 0; i < 26; i++)
            if(book[i] != 0)//AGCT��ĸ���ҳ���С�ȳ��ֵ���ĸ
                break;
        for(j = 0; j < len; j++)
        {
            if(s[j] - 'A' == i)//����С����ĸ����ַ���
            {
                if(flag == 0)
                {
                    res = s.substr(j) + s.substr(0,j);
                    flag++;
                }
                else
                {
                    temp = s.substr(j) + s.substr(0,j);
                    if(res > temp)//�Ƚϸ��½�����ַ����ıȽϾ��ǰ��ֵ���Ƚϵģ�
                    {
                        res = temp;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
