#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ion(int *book)//判断数组中的值是否全为0
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
        int i,wr = 0;//wr记录错的次数
        for(i = 0; i < s.length(); i++)//统计正确字符串中字母数量
            book[s[i] - 'a']++;
        for(i = 0; i < t.length(); i++)
        {
            if(ion(book))//数组全为0代表猜对了
                break;
            if(book[t[i] - 'a'] == 0)//重复猜和猜错都算猜错
                wr++;
            else//因为猜对某字母所有此字母都会显示
                book[t[i] - 'a'] = 0;//所以直接置0
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
