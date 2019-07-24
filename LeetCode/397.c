#include <stdio.h>
#include <stdlib.h>

int integerReplacement(int n){
        int count=0;
        long long int m=n;//中间防止超出int型的范围，所以用长整型
        while(m!=1){
            if(m%2==0){//如果是偶数，就除2
                m=m/2;
                count++;
            }
            else{
                if((m+1)%4==0&&m!=3){//要把3排除出去
                    m=m+1;
                    count++;
                }
                else{
                    m=m-1;
                    count++;
                }
            }
        }
        return count;
}
