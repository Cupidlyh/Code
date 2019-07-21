#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int i,a,b;
        for(i=1; i<=t; i++)
        {
            scanf("%d %d",&a,&b);
            if((a==10&&b>21)||a>10)
                printf("What a pity, it has passed!\n");
            if(a==10&&b==21)
                printf("It's today!!\n");
            if((a==10&&b<21)||a<10)
            {
                int sum=0;
                switch(a)
                {
                case 1:
                    sum=263+31-b;
                    break;
                case 2:
                    sum=235+28-b;
                    break;
                case 3:
                    sum=204+31-b;
                    break;
                case 4:
                    sum=174+30-b;
                    break;
                case 5:
                    sum=143+31-b;
                    break;
                case 6:
                    sum=113+30-b;
                    break;
                case 7:
                    sum=82+31-b;
                    break;
                case 8:
                    sum=51+31-b;
                    break;
                case 9:
                    sum=21+30-b;
                    break;
                case 10:
                    sum=0+21-b;
                    break;
                }
                printf("%d\n",sum);
            }

        }

    }
    return 0;
}
