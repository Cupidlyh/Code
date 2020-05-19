#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    double sum = 0.0,temp;
    int i;
    for(i = 0; i < 12; i++) {
        scanf("%lf",&temp);
        sum += temp;
    }
    printf("$%g",sum / 12);
    return 0;
}
