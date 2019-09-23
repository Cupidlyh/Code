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

typedef struct queue//ѭ������
{
    struct TreeNode *base[10000];
    int front;
    int rear;
} queue;

int maxLevelSum(struct TreeNode* root){
    long long int sum=0,sum1=0;//sum��¼ÿ������ĺͣ�sum1��¼ĿǰΪֹ�͵����ֵ
    int i=1,max=0;//i��¼������max��¼��ǰ���͵Ĳ���
    struct TreeNode *p;
    queue Q;
    Q.front=Q.rear=0;
    if(root)//������ڵ����
    {
        Q.base[Q.rear]=root;
        Q.rear=(Q.rear+1)%10000;
        Q.base[Q.rear]=NULL;//����NULL���ﵽ��ÿ��ֿ���Ŀ�ģ������¼����
        Q.rear=(Q.rear+1)%10000;
        while(Q.front!=Q.rear)//��α���
        {
            p=Q.base[Q.front];
            if(p==NULL) {//����ʱΪNULLʱ
                if(Q.base[(Q.front+1)%10000]!=NULL){//���������һ��ʱ
                    Q.base[Q.rear]=NULL;//����NULL�����µ�һ��Ҫ��ʼ��
                    Q.rear=(Q.rear+1)%10000;
                }
                if(sum>sum1) {//��ǰ�����ĺʹ���֮ǰ�ĺ�
                    sum1=sum;//��¼��������͵�ֵ
                    max=i;//��¼�²���
                }
                i++;//������1
                sum=0;//sum������Ϊ0���Ա��´ε�����
            }
            if(p!=NULL)//��p����NULLʱ��NULLֻ�ǽ�ÿ��ֿ���
                sum=sum+p->val;//����ǰ���Ԫ�غͼ������
            Q.front=(Q.front+1)%10000;
            if(p!=NULL){//��p����NULLʱ��NULLֻ�ǽ�ÿ��ֿ���
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
