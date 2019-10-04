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

int sumpath;//����·���ܺ�

bool Pathsummation(struct TreeNode* root, int sum) {
    sumpath = sumpath + root->val;//��·���ĺͼ��ϵ�ǰ����Ľڵ�ֵ
    if(root->left == NULL && root->right == NULL && sumpath == sum)//��������ʱ��˵���ҵ���һ��·����������
        return true;//����Ϊ��
    if(root->left == NULL && root->right == NULL && sumpath != sum){//����������ʱ
        sumpath = sumpath - root->val;//��Ϊ���ص���һ������������У�����Ҫ��·���ĺͼ�ȥ��ǰ����Ľڵ�ֵ
        return false;//����Ϊ��
    }
    if(root->left != NULL)//��ǰ�ڵ�������ʱ
        if(Pathsummation(root->left,sum) == true)
            return true;
    if(root->right != NULL)//��ǰ�ڵ����Һ���ʱ
        if(Pathsummation(root->right,sum) == true)
            return true;
    sumpath = sumpath - root->val;//������ֽڵ���Һ��ӱ����꣬��Ҫ�������˵���һ��
    return false;
}

bool hasPathSum(struct TreeNode* root, int sum){
    sumpath=0;
    if(root == NULL)//�������������κνڵ�ʱ
        return false;
     return Pathsummation(root,sum);
}
