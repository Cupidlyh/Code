#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[100005]= {'0'};
    while(gets(arr))
    {
        int num[30]= {0},i;
        for(i=0; i<strlen(arr); i++)
        {
            switch(arr[i])
            {
            case 'a':
                num[1]++;
                break;
            case 'b':
                num[2]++;
                break;
            case 'c':
                num[3]++;
                break;
            case 'd':
                num[4]++;
                break;
            case 'e':
                num[5]++;
                break;
            case 'f':
                num[6]++;
                break;
            case 'g':
                num[7]++;
                break;
            case 'h':
                num[8]++;
                break;
            case 'i':
                num[9]++;
                break;
            case 'j':
                num[10]++;
                break;
            case 'k':
                num[11]++;
                break;
            case 'l':
                num[12]++;
                break;
            case 'm':
                num[13]++;
                break;
            case 'n':
                num[14]++;
                break;
            case 'o':
                num[15]++;
                break;
            case 'p':
                num[16]++;
                break;
            case 'q':
                num[17]++;
                break;
            case 'r':
                num[18]++;
                break;
            case 's':
                num[19]++;
                break;
            case 't':
                num[20]++;
                break;
            case 'u':
                num[21]++;
                break;
            case 'v':
                num[22]++;
                break;
            case 'w':
                num[23]++;
                break;
            case 'x':
                num[24]++;
                break;
            case 'y':
                num[25]++;
                break;
            case 'z':
                num[26]++;
                break;
            }
        }
        printf("a:%d\n",num[1]);
        printf("b:%d\n",num[2]);
        printf("c:%d\n",num[3]);
        printf("d:%d\n",num[4]);
        printf("e:%d\n",num[5]);
        printf("f:%d\n",num[6]);
        printf("g:%d\n",num[7]);
        printf("h:%d\n",num[8]);
        printf("i:%d\n",num[9]);
        printf("j:%d\n",num[10]);
        printf("k:%d\n",num[11]);
        printf("l:%d\n",num[12]);
        printf("m:%d\n",num[13]);
        printf("n:%d\n",num[14]);
        printf("o:%d\n",num[15]);
        printf("p:%d\n",num[16]);
        printf("q:%d\n",num[17]);
        printf("r:%d\n",num[18]);
        printf("s:%d\n",num[19]);
        printf("t:%d\n",num[20]);
        printf("u:%d\n",num[21]);
        printf("v:%d\n",num[22]);
        printf("w:%d\n",num[23]);
        printf("x:%d\n",num[24]);
        printf("y:%d\n",num[25]);
        printf("z:%d\n",num[26]);
        printf("\n");
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
