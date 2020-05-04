int jump(int* nums, int numsSize){
    //step步数,end记录当前跳跃次数内的下一步最大下标,maxpos记录i到end(当前步骤)的下一跳的最大长度
    int step = 0,end = 0,maxpos = 0;
    for(int i = 0; i < numsSize - 1; i++) {
        maxpos = maxpos > i + nums[i] ? maxpos : i + nums[i];
        if(i == end) {
            end = maxpos;
            step++;
        }
    }
    return step;
}