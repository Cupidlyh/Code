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

struct loop//ѭ������
{
    Node *base[1000];
    int front;
    int rear;
};

int maxDepth(Node* root){//��������������
    if(root==NULL)
        return 0;
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

void levelorder(Node *root)//�������Ĳ�α���
{
    Node *p;
    struct loop Q;
    int maxdepth=maxDepth(root),depth=0;
    Q.front=Q.rear=0;
    if(root)
    {
        Q.base[Q.rear]=root;
        Q.rear=(Q.rear+1)%1000;
        Q.base[Q.rear]=NULL;//����NULL���ﵽ��ÿ��ֿ���Ŀ�ģ������¼����
        Q.rear=(Q.rear+1)%1000;
        while(Q.front!=Q.rear)
        {
            p=Q.base[Q.front];
            if(p&&Q.base[(Q.front+1)%1000]!=NULL)//p��ΪNULL������p�ұߴ��ڽڵ�ʱ
                p->next=Q.base[(Q.front+1)%1000];
            if(p==NULL)//��pΪNULLʱ
            {
                Q.base[Q.rear]=NULL;//����NULL�����µ�һ��Ҫ��ʼ��
                Q.rear=(Q.rear+1)%1000;
                depth++;//������1
                if(depth==maxdepth)//�����һ���Ѿ���������ʱ��������whileѭ��
                break;
            }
            Q.front=(Q.front+1)%1000;
            if(p!=NULL)//��p�����Ľڵ�ʱ
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
