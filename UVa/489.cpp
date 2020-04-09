#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ion(int *book)//�ж������е�ֵ�Ƿ�ȫΪ0
{
    for(int i = 0; i < 26; i++)
        if(book[i] != 0)
            return false;
    return true;
}

int main()
{
    int A;
    string s,t;
    int book[26];
    while(scanf("%d",&A) != EOF)
    {
        if(A == -1)
            break;
        memset(book,0,sizeof(book));
        printf("Round %d\n",A);
        cin>>s>>t;
        int i,wr = 0;//wr��¼��Ĵ���
        for(i = 0; i < s.length(); i++)//ͳ����ȷ�ַ�������ĸ����
            book[s[i] - 'a']++;
        for(i = 0; i < t.length(); i++)
        {
            if(ion(book))//����ȫΪ0����¶���
                break;
            if(book[t[i] - 'a'] == 0)//�ظ��ºͲ´���´�
                wr++;
            else//��Ϊ�¶�ĳ��ĸ���д���ĸ������ʾ
                book[t[i] - 'a'] = 0;//����ֱ����0
        }
        if(wr < 7 && ion(book))
            printf("You win.\n");
        if(wr < 7 && !ion(book))
            printf("You chickened out.\n");
        if(wr >= 7)
            printf("You lose.\n");

    }
    return 0;
}
