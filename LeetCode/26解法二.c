

int removeDuplicates(int* nums, int numsSize){
            int i,j=0;
            for(i=0;i<numsSize-1;i++)//注意这里是数组的大小减去一，防止下面if判断越界
                if(nums[i]!=nums[i+1])
                    nums[j++]=nums[i];//不相等时从数组下标为0开始依次存进数组中
            if(numsSize!=0)
            nums[j++]=nums[numsSize-1];//数组不为空时，最后一项要存进去，因为如果最后一项和前面的相等，不满足判断条件
            //所以无法存进，要在这步存入，而不相等时最后一项没遍历到，所以要在这一步存入
            return j;
}

