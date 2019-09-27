#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

struct loop//循环队列
{
    Node *base[1000];
    int front;
    int rear;
};

int maxDepth(Node* root){//计算树的最大深度
    if(root==NULL)
        return 0;
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

void levelorder(Node *root)//二叉树的层次遍历
{
    Node *p;
    struct loop Q;
    int maxdepth=maxDepth(root),depth=0;
    Q.front=Q.rear=0;
    if(root)
    {
        Q.base[Q.rear]=root;
        Q.rear=(Q.rear+1)%1000;
        Q.base[Q.rear]=NULL;//放入NULL来达到将每层分开的目的，方便记录层数
        Q.rear=(Q.rear+1)%1000;
        while(Q.front!=Q.rear)
        {
            p=Q.base[Q.front];
            if(p&&Q.base[(Q.front+1)%1000]!=NULL)//p不为NULL，并且p右边存在节点时
                p->next=Q.base[(Q.front+1)%1000];
            if(p==NULL)//当p为NULL时
            {
                Q.base[Q.rear]=NULL;//加入NULL代表新的一层要开始了
                Q.rear=(Q.rear+1)%1000;
                depth++;//层数加1
                if(depth==maxdepth)//当最后一层已经遍历结束时，就跳出while循环
                break;
            }
            Q.front=(Q.front+1)%1000;
            if(p!=NULL)//当p是树的节点时
            {
                if(p->left)
                {
                    Q.base[Q.rear]=p->left;
                    Q.rear=(Q.rear+1)%1000;
                }
                if(p->right)
                {
                    Q.base[Q.rear]=p->right;
                    Q.rear=(Q.rear+1)%1000;
                }
            }
        }
    }
    return ;
}

class Solution {
public:
    Node* connect(Node* root) {
        levelorder(root);
        return root;
    }
};
