#include <stdio.h>
#include <stdlib.h>

int numJewelsInStones(char * J, char * S){
    int map_min[26] = {0},map_max[26] = {0},i,res = 0;
    for(i = 0; i < strlen(J); i++) {//ͳ�Ʊ�ʯ������
        if(J[i] >= 'a' && J[i] <= 'z')
            map_min[J[i] - 'a'] = 1;
        if(J[i] >= 'A' && J[i] <= 'Z')
            map_max[J[i] - 'A'] = 1;
    }
    for(i = 0; i < strlen(S); i++) {//�ҳ����еı�ʯ
        if(S[i] >= 'a' && S[i] <= 'z')
            if(map_min[S[i] - 'a'] == 1)
                res++;
        if(S[i] >= 'A' && S[i] <= 'Z')
            if(map_max[S[i] - 'A'] == 1)
                res++;
    }
    return res;
}
