#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 1;//计数
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == '"') {
            printf("%s",(num % 2 != 0) ? "``" : "''");
            num++;
        }
        else
            printf("%c",c);
    }
    return 0;
}
