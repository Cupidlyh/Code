#include <stdio.h>
#include <stdlib.h>

bool canConstruct(char * ransomNote, char * magazine){
            bool cans;
            int count[26]={},counts[26]={},i,j,flag;
            for(i=0;i<strlen(ransomNote);i++)
                count[ransomNote[i]-'a']=count[ransomNote[i]-'a']+1;//��¼��һ���ַ�����ÿ����ĸ���ֵĴ���
            for(j=0;j<strlen(magazine);j++)
                counts[magazine[j]-'a']=counts[magazine[j]-'a']+1;//��¼�ڶ����ַ�����ÿ����ĸ���ֵĴ���
            for(i=0;i<26;i++)
                if(count[i]<=counts[i])
                    flag=1;
                else{
                    flag=0;
                    break;
                }
            if(flag==0)
                cans=false;
            else
                cans=true;
            return cans;

}

