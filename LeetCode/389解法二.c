

char findTheDifference(char * s, char * t){
    int i,findTheDifference;
    findTheDifference=(int)t[0];//����ת��
    for(i=0;i<strlen(s);i++){
        findTheDifference=findTheDifference^(int)s[i];//�������
        findTheDifference=findTheDifference^(int)t[i+1];//�������
    }
    return (char)findTheDifference;//����ת��
}

