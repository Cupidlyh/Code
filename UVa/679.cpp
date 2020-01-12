#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int D,I,A;
    while(cin>>A)
    {
        if(A == -1)
            break;
        while(A--)
        {
            cin>>D>>I;
            int i,k = 1;
            //前两个小球必定一个在左子树，一个在右子树，所以我们可以直接按照小球的编号来判断它的走向
            for(i = 0; i < D - 1; i++)//二叉树的层数
                if(I % 2 == 0)//小球号码为偶数，它是往右走的第I/2个小球
                {
                    k = 2 * k + 1;
                    I = I / 2;
                }
                else//小球号码为奇数，它是往左走的第I+1/2个小球
                {
                    I = (I + 1) / 2;
                    k = 2 * k;
                }
            cout<<k<<endl;
        }
    }
    return 0;
}
