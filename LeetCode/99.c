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

struct TreeNode *base[1000];
int n;
long long int arr[1000];

int cmp(const void *a,const void *b) {//��С��������
    const long long int p1 = *(const long long int*)a;
    const long long int p2 = *(const long long int*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}

void inorder(struct TreeNode* t){//�ݹ��������
    if(t){
        inorder(t->left);
        base[n] = t;//�浱ǰ�ڵ�
        arr[n++] = t -> val;//�浱ǰ�ڵ��ֵ
        inorder(t->right);
    }
}

void recoverTree(struct TreeNode* root){
    n = 0;
    inorder(root);//�������
    qsort(arr,n,sizeof(arr[0]),cmp);//����
    int i,temp,num = 0;//num��Ϊ�˼�¼�ҵ��ڼ�����ͬ��Ԫ��
    for(i = 0; i < n; i++) {
        if(arr[i] != base[i] -> val) {//Ѱ�Ҳ�ͬ��Ԫ��
            if(num == 0) {//���ҵ���һ����ͬ��Ԫ��ʱ
                temp = i;//��¼��������±�
            }
            num++;
            if(num == 2)//���ҵ��ڶ�����ͬ��Ԫ��ʱ
                break;
        }
    }
    num = base[temp] -> val;//���������ڵ��ֵ
    base[temp] -> val = base[i] -> val;
    base[i] -> val = num;
}
