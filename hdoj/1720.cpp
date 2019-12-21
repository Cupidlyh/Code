#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    char A[100] = {'0'},B[100] = {'0'};//用来存十六进制数
    while(cin>>A>>B)//多次输入
    {
        int sum = 0,len = strlen(A),i,bit = 0;
        for(i = len - 1; i >= 0; i--)//十六进制的A转换成十进制数
        {
            int temp;
            if(A[i] >= 'A' && A[i] <= 'F')
                temp = A[i] - '0' - 7;
            else if (A[i] >= 'a' && A[i] <= 'f')
                temp = A[i] - '0' - 39;
            else
                temp = A[i] - '0';
            sum = sum + ((int)(pow(16.0,bit++) + 0.5)) * temp;
        }
        len = strlen(B);
        bit = 0;
        for(i = len - 1; i >= 0; i--)//十六进制的B转换成十进制数
        {
            int temp;
            if(B[i] >= 'A' && B[i] <= 'F')
                temp = B[i] - '0' - 7;
            else if (B[i] >= 'a' && B[i] <= 'f')
                temp = B[i] - '0' - 39;
            else
                temp = B[i] - '0';
            sum = sum + ((int)(pow(16.0,bit++) + 0.5)) * temp;
        }
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        cout<<sum<<endl;
    }

    return 0;
}
