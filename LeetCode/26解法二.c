

int removeDuplicates(int* nums, int numsSize){
            int i,j=0;
            for(i=0;i<numsSize-1;i++)//ע������������Ĵ�С��ȥһ����ֹ����if�ж�Խ��
                if(nums[i]!=nums[i+1])
                    nums[j++]=nums[i];//�����ʱ�������±�Ϊ0��ʼ���δ��������
            if(numsSize!=0)
            nums[j++]=nums[numsSize-1];//���鲻Ϊ��ʱ�����һ��Ҫ���ȥ����Ϊ������һ���ǰ�����ȣ��������ж�����
            //�����޷������Ҫ���ⲽ���룬�������ʱ���һ��û������������Ҫ����һ������
            return j;
}

