#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    char in[105];
    char ans[200];
    int in_len,num = 0,start_bit;
    memset(in,0,sizeof(in));
    for (int i = 0; i < 200; i++)
        ans[i] = '0';
    while (gets(in))
    {
        in_len = strlen(in);
        if (in_len == 1 && in[0] == '0')
            break;
        int ans_bit = 199;
        if (num == 0)
        {
            for (int i = in_len - 1; i >= 0; i--)
            {
                ans[ans_bit--] = in[i];
            }
        }
        else
        {
            int carry = 0;//½øÎ»
            int in_num,ans_num,sum;
            for (int i = in_len - 1; i >= 0; i--)
            {
                sum = 0;
                in_num = in[i] - '0';
                ans_num = ans[ans_bit] - '0';
                sum = in_num + ans_num + carry;
                carry = sum / 10;
                ans[ans_bit] = sum % 10 + '0';
                ans_bit--;
            }
            while (carry != 0)
            {
                sum = ans[ans_bit] - '0' + carry;
                carry = sum / 10;
                ans[ans_bit] = sum % 10 + '0';
                ans_bit--;
            }
        }
        memset(in,0,sizeof(in));
        num++;
    }
    for (int i = 0; i < 200; i++)
    {
        if (ans[i] != '0')
        {
            start_bit = i;
            break;
        }
    }
    for (int i = start_bit; i < 200; i++)
        printf("%c",ans[i]);
    printf("\n");
    return 0;
}
