#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        //map统计A数组中元素出现的个数，因为A可能给你40000个39999，所以map要开到80000
        int map[80000] = {0};
        int i,j,res = 0;
        for(i = 0; i < A.size(); i++)//统计A数组元素出现的个数
            map[A[i]]++;
        for(i = 0; i < 80000; i++) {
            if(map[i] <= 1)//元素出现次数小于等于1要跳过（因为进行的是增量操作）
                continue;
            while(map[i] > 1) {//每个元素最多只出现一次（循环终止条件）
                map[i]--;
                for(j = i + 1; j < 80000; j++)//在此元素之后寻找第一个没出现过的元素
                    if(map[j] == 0) {
                        map[j] = 1;//标记
                        res += j - i;//添加操作次数（每操作一次增长1）
                        break;
                    }
            }
        }
        return res;
    }
};
