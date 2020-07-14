#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

//原数组为nums，将nums离散化，此处是排序+去重，转化为数组a
vector<int> a;

//离散化处理
void Discretization(vector<int>& nums)
{
    //拷贝数组[1000,1000,10000,10000,1,100,1005,65]
    a.assign(nums.begin(), nums.end());
    //排序[1,65,100,1000,1000,1005,10000,10000]
    sort(a.begin(), a.end());
    //去重[1,65,100,1000,1005,10000]
    a.erase(unique(a.begin(), a.end()), a.end());
}

//离散化处理后数据的位置
int getId(int x)
{
    //lower_bound()返回第一个不小于x的迭代器
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

//数据离散化处理的目的是节省空间，因为当数据稀疏时，你数组可能会开到超内存限制的程度，
//但是离散化处理就将数据范围变成了只看相对的大小，而不是实际值，可以节省空间
int main()
{
    vector<int> nums;
    nums.push_back(1000);
    nums.push_back(1000);
    nums.push_back(10000);
    nums.push_back(10000);
    nums.push_back(1);
    nums.push_back(100);
    nums.push_back(1005);
    nums.push_back(65);
    //离散化处理
    Discretization(nums);
    //离散化后nums数组中数字的id（相对位置）
    for(int i = 0; i < nums.size(); i++)
    {
        int id = getId(nums[i]);
        cout<<nums[i]<<"  "<<id<<endl;
    }
    return 0;
}
