#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct queue//循环队列
{
    struct TreeNode *base[10000];
    int front;
    int rear;
} queue;

int maxLevelSum(struct TreeNode* root){
    long long int sum=0,sum1=0;//sum记录每层运算的和，sum1记录目前为止和的最大值
    int i=1,max=0;//i记录层数，max记录当前最大和的层数
    struct TreeNode *p;
    queue Q;
    for(int i=0;i<10000;i++)//将队列中的base数组初始化为NULL
        Q.base[i]=NULL;
    Q.front=Q.rear=0;
    if(root)//如果根节点存在
    {
        Q.base[Q.rear]=root;
        Q.rear=(Q.rear+1)%10000;
        Q.base[Q.rear]=NULL;//放入NULL来达到将每层分开的目的，方便记录层数
        Q.rear=(Q.rear+1)%10000;
        while(Q.front!=Q.rear)//层次遍历
        {
            p=Q.base[Q.front];
            if(p==NULL) {//当此时为NULL时
                if(Q.base[(Q.front+1)%10000]!=NULL){//当不是最后一层时
                    Q.base[Q.rear]=NULL;//加入NULL代表新的一层要开始了
                    Q.rear=(Q.rear+1)%10000;
                }
                if(sum>sum1) {//当前层数的和大于之前的和
                    sum1=sum;//记录下来这个和的值
                    max=i;//记录下层数
                }
                i++;//层数加1
                sum=0;//sum重新置为0，以便下次的运算
            }
            if(p!=NULL)//当p不是NULL时（NULL只是将每层分开）
                sum=sum+p->val;//将当前层的元素和计算出来
            Q.front=(Q.front+1)%10000;
            if(p!=NULL){//当p不是NULL时（NULL只是将每层分开）
                if(p->left)
                {
                    Q.base[Q.rear]=p->left;
                    Q.rear=(Q.rear+1)%10000;
                }
                if(p->right)
                {
                    Q.base[Q.rear]=p->right;
                    Q.rear=(Q.rear+1)%10000;
                }
            }
        }
    }
    return max;
}
