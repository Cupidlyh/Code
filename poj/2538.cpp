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
    //这里是'\\'两个，原因是在转义字符中'\\'就代表'\'
    char mapp[50] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char in[100];
    while (gets(in) != NULL)
    {
        for (int i = 0; i < strlen(in); i++)
        {
            if (in[i] == ' ')
                printf(" ");
            else
            {
                for (int j = 0; j < 50; j++)
                {
                    if (mapp[j] == in[i])
                    {
                        printf("%c",mapp[j - 1]);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
