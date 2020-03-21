#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)
            return false;
        if(z == 0 || x + y == z)
            return true;
        return z % gcd(x, y) == 0;
    }
};
