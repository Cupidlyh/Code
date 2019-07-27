int searchInsert(int* nums, int numsSize, int target){
    int left=0,right=numsSize-1,mid;
    if(nums[right]<target)//如果所给值大于数组中最后一个元素，直接返回numsSize
        return numsSize;
    while(left<right){//二分查找左边界
        mid=left+(right-left)/2;
        if(nums[mid]==target)
            right=mid;
        if(nums[mid]<target)
            left=mid+1;
        if(nums[mid]>target)
            right=mid;
    }
    return left;
}