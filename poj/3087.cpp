#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 1; z <= n; z++)
    {
        char s1[102] = {'0'},s2[102] = {'0'},s[204] = {'0'},res[204] = {'0'};
        int c,i,num = 0;//num记录洗牌次数
        map<string,int>book;
        cin>>c>>s1>>s2>>res;
        while(true)
        {
            int m = 0;
            for(i = 0; i < c; i++)//洗牌
            {
                s[m++] = s2[i];
                s[m++] = s1[i];
            }
            s[m] = '\0';
            //判断此时洗牌后的情况之前是否出现过，出现过就说明找不到最后题意要的结果
            if(book[s] == 1)
            {
                cout<<z<<' '<<-1<<endl;
                break;
            }
            num++;//洗牌次数加1
            book[s] = 1;
            if(strcmp(s,res) == 0)//如果和题意的结果一样
            {
                cout<<z<<' '<<num<<endl;
                break;
            }
            m = 0;
            for(i = 0; i < c; i++)//重新分牌来进行下一次的洗牌
                s1[m++] = s[i];
            s1[m] = '\0';
            m = 0;
            for(; i < 2 * c; i++)
                s2[m++] = s[i];
            s2[m] = '\0';
        }
    }
    return 0;
}
