#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    char s[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    char c;
    while((c = getchar()) != EOF)
    {
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] == c)
            {
                cout<<s[i - 1];
                break;
            }
        }
        if(i == strlen(s))
            cout<<c;
    }
    return 0;
}
