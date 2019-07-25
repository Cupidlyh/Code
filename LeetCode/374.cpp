#include <iostream>

using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int i=1,ans,j=n,num;
        while(i<=j){//while循环里就是二分查找算法
            num=i+(j-i)/2;
            if(guess(num)==0){//判断数组是否相等
                ans=num;//相等说明找到了
                break;
            }
            if(guess(num)==-1)//如果猜的太大了，缩小右边界
                j=num-1;
            if(guess(num)==1)//如果猜的太小了，缩小左边界
                i=num+1;
        }
        return ans;
};
};
