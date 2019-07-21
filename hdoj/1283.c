#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int m1,m2;
    char arr[205]= {'0'};
    while(scanf("%d %d %s",&m1,&m2,arr)!=EOF)
    {
        int r1=0,r2=0,r3=0,i;
        for(i=0; i<strlen(arr); i++)
        {
            switch(arr[i])
            {
            case 'A':
                r1=m1;
                break;
            case 'B':
                r2=m2;
                break;
            case 'C':
                m1=r3;
                break;
            case 'D':
                m2=r3;
                break;
            case 'E':
                r3=r1+r2;
                break;
            case 'F':
                r3=r1-r2;
                break;
            }
        }
        printf("%d,%d\n",m1,m2);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
