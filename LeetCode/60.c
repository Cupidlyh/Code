#include <stdio.h>
#include <stdlib.h>

int sum;

void dfs(int *nums,char *per,int *temp,int *map,int m,int numsSize) {
    if(m==numsSize) {//�����������������֮��
       sum=sum-1;//���еĸ�����1
        if(sum==0) {//���ҵ���K������ʱ
            for(int k=0;k<numsSize;k++)
                per[k]=temp[k]+'0';//����ʱ�洢Ԫ�������е�Ԫ�ش浽���������
        }
        return ;
    }
    int i;
    for(i=0;i<numsSize;i++) {//������Ŀ������һά����
        if(map[i]==0){//�ҵ�û����ǵ�����
        map[i]=1;//�������
        temp[m]=nums[i];//���������ʱ�洢Ԫ�ص�������
        dfs(nums,per,temp,map,m+1,numsSize);
        map[i]=0;//�ݹ���û��˳���ʱ��Ҫ�������ֵı�����
        }
    }
    return ;
}

char * getPermutation(int n, int k){
    int nums[12],i,j=0,temp[n],map[12]={0};//map�Ǳ�����飬temp����ʱ��¼Ԫ�ص�����,nums�Ǵ洢Ԫ�ص�����
    sum=k;
    char *per=(char *)malloc((n+1)*sizeof(char));//��¼���������
    for(i=1;i<=n;i++)//�洢Ԫ�ؽ�nums������
        nums[j++]=i;
    dfs(nums,per,temp,map,0,n);
    per[n]='\0';//����������Ҫ��һ��������
    return per;

}


