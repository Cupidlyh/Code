#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            char arr[30]= {'0'};
            scanf("%s",arr);
            int len=strlen(arr);
            if(arr[0]!='-'&&arr[len-1]!='0')
            {
                for(int i=len-1; i>=0; i--)
                    printf("%c",arr[i]);
                printf("\n");
            }
            if(arr[0]=='-'&&arr[len-1]!='0')
            {
                printf("-");
                for(int i=len-1; i>=1; i--)
                    printf("%c",arr[i]);
                printf("\n");
            }
            if(arr[0]=='-'&&arr[len-1]=='0')
            {
                printf("-");
                int k=len-1,j=0;
                while(arr[k]=='0')
                {
                    k--;
                    j++;
                }
                for(int i=k; i>=1; i--)
                    printf("%c",arr[i]);
                for(int i=0; i<j; i++)
                    printf("0");
                printf("\n");
            }
            if(arr[0]!='-'&&arr[len-1]=='0')
            {
                int k=len-1,j=0;
                while(arr[k]=='0')
                {
                    k--;
                    j++;
                }
                for(int i=k; i>=0; i--)
                    printf("%c",arr[i]);
                for(int i=0; i<j; i++)
                    printf("0");
                printf("\n");
            }
        }
    }
    return 0;
}
