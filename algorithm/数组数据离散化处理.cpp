#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

//ԭ����Ϊnums����nums��ɢ�����˴�������+ȥ�أ�ת��Ϊ����a
vector<int> a;

//��ɢ������
void Discretization(vector<int>& nums)
{
    //��������[1000,1000,10000,10000,1,100,1005,65]
    a.assign(nums.begin(), nums.end());
    //����[1,65,100,1000,1000,1005,10000,10000]
    sort(a.begin(), a.end());
    //ȥ��[1,65,100,1000,1005,10000]
    a.erase(unique(a.begin(), a.end()), a.end());
}

//��ɢ����������ݵ�λ��
int getId(int x)
{
    //lower_bound()���ص�һ����С��x�ĵ�����
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

//������ɢ�������Ŀ���ǽ�ʡ�ռ䣬��Ϊ������ϡ��ʱ����������ܻῪ�����ڴ����Ƶĳ̶ȣ�
//������ɢ������ͽ����ݷ�Χ�����ֻ����ԵĴ�С��������ʵ��ֵ�����Խ�ʡ�ռ�
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
    //��ɢ������
    Discretization(nums);
    //��ɢ����nums���������ֵ�id�����λ�ã�
    for(int i = 0; i < nums.size(); i++)
    {
        int id = getId(nums[i]);
        cout<<nums[i]<<"  "<<id<<endl;
    }
    return 0;
}
