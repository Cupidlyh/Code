int singleNumber(int* nums, int numsSize){
        int singleNumber=0,i;
    for(i=0;i<numsSize;i++){
       singleNumber=nums[i]^singleNumber;//Òì»òÔËËã
    }
        return singleNumber;
}