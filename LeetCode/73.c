#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,flag=0;//flag������ǵ�0���Ƿ���Ҫ��Ϊ0
    for(i=0;i<matrixSize;i++){//����һ������
        for(j=0;j<*matrixColSize;j++){
            if(matrix[i][j]==0){//������0Ԫ�ص���һ�к���һ�е���Ԫ�ر��Ϊ0
                if(j==0)
                    flag=1;//����ǵ�0����Ҫ��Ǿ���flag�����
                else
                    matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(i=1;i<matrixSize;i++){//���жϳ�ȥ��0�������е���Ԫ��
        if(matrix[i][0]==0){//�������
            for(j=0;j<* matrixColSize;j++)//��һ��ȫ��Ϊ0
                matrix[i][j]=0;
        }
    }
    for(j=1;j<* matrixColSize;j++){//���жϳ�ȥ��0�������е���Ԫ��
        if(matrix[0][j]==0){//�����0
            for(i=0;i<matrixSize;i++)//��һ��ȫ��Ϊ0
                matrix[i][j]=0;
        }
    }
    if(matrix[0][0]==0)//�жϵ�0�е���Ԫ���Ƿ�Ϊ0
        for(j=0;j<* matrixColSize;j++)
            matrix[0][j]=0;
    if(flag==1)//�жϵ�0�е���Ԫ���Ƿ񱻱��
        for(i=0;i<matrixSize;i++)
            matrix[i][0]=0;
}
