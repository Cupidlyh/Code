#include <stdio.h>
#include <stdlib.h>

static int arr[10000],j;//ȫ�ֱ���

void inorder(struct TreeNode* t){//�����������
    if(t){
        inorder(t->left);
        arr[j++]=t->val;//��Ԫ�ش��������
        inorder(t->right);
    }
}

bool isValidBST(struct TreeNode* root){
    int i;
    j=0;
    memset(arr,0,sizeof(arr));//�����ʼ��
    inorder(root);//�������
    for(i=0;i<j-1;i++){
        if(arr[i]>=arr[i+1]){//�����������˵�����Ƕ���������
            return false;
        }
    }
    return true;
}
