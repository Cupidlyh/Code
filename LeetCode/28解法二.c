void pre_next(char *str,int *next,int len){
    int k=-1,i;
    next[0]=-1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    for(i=1;i<len;i++){
        while(k>-1&&str[k+1]!=str[i])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
            k=next[k];//继续往前判断
        if(str[k+1]==str[i])
            k=k+1;
        next[i]=k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
                       //如果next[i]=0，说明存在一个长度的相同的最大前缀和最大后缀，以此类推
    }
}

int strStr(char * haystack, char * needle){
    int h_len=strlen(haystack),n_len=strlen(needle),i,k=-1;
    if(n_len==0)//短串长度为0时肯定是任何字符串的子串，所以返回0
        return 0;
    int* next=(int *)malloc(100000*sizeof(int));
    memset(next,0,100000*sizeof(next[0]));//数组初始化
    pre_next(needle,next,n_len);//对短串进行预处理
    for(i=0;i<h_len;i++){
        while(k>-1&&needle[k+1]!=haystack[i])
            k=next[k];
        if(needle[k+1]==haystack[i])
            k=k+1;
        if(k==n_len-1)//说明k移动到短串的最末端
            return i-n_len+1;
    }
    return -1;
}