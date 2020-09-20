#include <iostream>
#include<algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int M,N;
    while (scanf("%d %d",&M,&N) != EOF)
    {
        if (M == -1 && N == -1)
            break;
        double J[1005] = {0},F[1005] = {0};
        for (int i = 0; i < N; i++)
        {
            scanf("%lf %lf",&J[i],&F[i]);
        }
        //按猫粮换JavaBeans的比例,从大到小排,就可以换取更多的JavaBeans
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if ((J[i] / F[i]) < (J[j] / F[j]))
                {
                    double temp;
                    temp = J[i];
                    J[i] = J[j];
                    J[j] = temp;
                    temp = F[i];
                    F[i] = F[j];
                    F[j] = temp;
                }
            }
        }
        double sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (M == 0)
                break;
            if (M > F[i])
            {
                sum += J[i];
                M -= F[i];
            }
            else
            {
                sum += J[i] * M / F[i];
                M = 0;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
