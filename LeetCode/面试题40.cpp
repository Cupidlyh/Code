#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>res;
        sort(arr.begin(),arr.end());
        for(int i = 0; i < k; i++)
            res.push_back(arr[i]);
        return res;
    }
};
