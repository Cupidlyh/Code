#include <stdio.h>
#include <stdlib.h>

int minSteps(char * s, char * t){
    int nums[26] = {0},numt[26] = {0};//�ֱ��¼��s��t��������ĸ���ֵĴ���
    int i,res = 0;
    for(i = 0; i < strlen(s); i++) {//��Ϊ�������鳤��һ��������һ�α���
        nums[s[i] - 'a']++;
        numt[t[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {//������¼����������
        if(numt[i] >= nums[i]) {//���t������ĸ���ֵ����δ���s����
            nums[i] = 0;//s�������
        }
        else {//���t������ĸ���ֵ�����С��s����
            nums[i] = nums[i] - numt[i];//s�������s�����t����
        }
        res = res + nums[i];//��Ϊ��t���s����С����������s�����t����֮�����ĸ�����s�е���ĸ��t�г��ֵľͲ��ö�������Ļ���û���ֹ����滻����Ӧ����ĸ��
    }
    return res;
}
