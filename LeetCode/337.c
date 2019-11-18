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

int max(int a,int b) {//�Ƚϴ�С
    if(a > b)
        return a;
    else
        return b;
}

int rob(struct TreeNode* root){
    if(root == NULL)
            return 0;
    //�ֱ��ʾ���ӣ����ӵ����ӣ����ӵ��Һ��ӣ��Һ��ӣ��Һ��ӵ��Һ��ӣ��Һ��ӵ�����
    int left = 0,leftl = 0,leftr = 0,right = 0,rightr = 0,rightl = 0;
    left = rob(root -> left);//�ݹ�������ӵ����ֵ
    right = rob(root -> right);//�ݹ�����Һ��ӵ����ֵ
    if(root -> left) {//������Ӵ���
        leftl = rob(root -> left -> left);//�ݹ�������ӵ����ӵ����ֵ
        leftr = rob(root -> left -> right);//�ݹ�������ӵ��Һ��ӵ����ֵ
    }
    if(root -> right) {//����Һ��Ӵ���
        rightl = rob(root -> right -> left);//�ݹ�����Һ��ӵ����ӵ����ֵ
        rightr = rob(root -> right -> right);//�ݹ�����Һ��ӵ��Һ��ӵ����ֵ
    }
    //��͵ȡ��ǰ���ڵ�Ͳ�͵ȡ��ǰ���ڵ������������ѡһ���ϴ��
    return max(left + right,root -> val + leftl + leftr + rightl + rightr);
}
