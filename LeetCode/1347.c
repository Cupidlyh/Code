#include <stdio.h>
#include <stdlib.h>

int minSteps(char * s, char * t){
    int nums[26] = {0},numt[26] = {0};//分别记录是s和t数组中字母出现的次数
    int i,res = 0;
    for(i = 0; i < strlen(s); i++) {//因为两个数组长度一样，所以一次遍历
        nums[s[i] - 'a']++;
        numt[t[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {//遍历记录次数的数组
        if(numt[i] >= nums[i]) {//如果t数组字母出现的数次大于s数组
            nums[i] = 0;//s数组归零
        }
        else {//如果t数组字母出现的数次小于s数组
            nums[i] = nums[i] - numt[i];//s数组等于s数组减t数组
        }
        res = res + nums[i];//因为是t变成s，最小步骤数等于s数组和t数组之间的字母差（就是s中的字母在t中出现的就不用动，多余的或者没出现过的替换成相应的字母）
    }
    return res;
}
