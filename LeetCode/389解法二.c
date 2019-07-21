

char findTheDifference(char * s, char * t){
    int i,findTheDifference;
    findTheDifference=(int)t[0];//类型转换
    for(i=0;i<strlen(s);i++){
        findTheDifference=findTheDifference^(int)s[i];//异或运算
        findTheDifference=findTheDifference^(int)t[i+1];//异或运算
    }
    return (char)findTheDifference;//类型转换
}

