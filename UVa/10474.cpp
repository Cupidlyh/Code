#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int Q,N,num = 1;
    while(cin>>N>>Q)
    {
        if(Q == 0 && N == 0)
            break;
        int i,exe[10002] = {0},que[Q];
        for(i = 0; i < N; i++)
            cin>>exe[i];
        for(i = 0; i < Q; i++)
            cin>>que[i];
        cout<<"CASE# "<<num<<':'<<endl;
        sort(exe,exe + N);//从小到大排序
        int q = 0;
        while(q < Q)
        {
            if(exe[N - 1] < que[q])
                cout<<que[q]<<" not found"<<endl;
            else
            {
                for(i = 0; i < N; i++)
                {
                    if(exe[i] == que[q])
                    {
                        cout<<que[q]<<" found at "<<i + 1<<endl;
                        break;
                    }
                    if(exe[i] > que[q])
                    {
                        cout<<que[q]<<" not found"<<endl;
                        break;
                    }
                }
            }
            q++;
        }
        num++;
    }
    return 0;
}
