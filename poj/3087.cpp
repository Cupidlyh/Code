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
        int c,i,num = 0;//num��¼ϴ�ƴ���
        map<string,int>book;
        cin>>c>>s1>>s2>>res;
        while(true)
        {
            int m = 0;
            for(i = 0; i < c; i++)//ϴ��
            {
                s[m++] = s2[i];
                s[m++] = s1[i];
            }
            s[m] = '\0';
            //�жϴ�ʱϴ�ƺ�����֮ǰ�Ƿ���ֹ������ֹ���˵���Ҳ����������Ҫ�Ľ��
            if(book[s] == 1)
            {
                cout<<z<<' '<<-1<<endl;
                break;
            }
            num++;//ϴ�ƴ�����1
            book[s] = 1;
            if(strcmp(s,res) == 0)//���������Ľ��һ��
            {
                cout<<z<<' '<<num<<endl;
                break;
            }
            m = 0;
            for(i = 0; i < c; i++)//���·�����������һ�ε�ϴ��
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
