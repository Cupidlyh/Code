#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int D,I,A;
    while(cin>>A)
    {
        if(A == -1)
            break;
        while(A--)
        {
            cin>>D>>I;
            int i,k = 1;
            //ǰ����С��ض�һ������������һ�������������������ǿ���ֱ�Ӱ���С��ı�����ж���������
            for(i = 0; i < D - 1; i++)//�������Ĳ���
                if(I % 2 == 0)//С�����Ϊż�������������ߵĵ�I/2��С��
                {
                    k = 2 * k + 1;
                    I = I / 2;
                }
                else//С�����Ϊ���������������ߵĵ�I+1/2��С��
                {
                    I = (I + 1) / 2;
                    k = 2 * k;
                }
            cout<<k<<endl;
        }
    }
    return 0;
}
