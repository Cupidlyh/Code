#include <stdio.h>
#include <stdlib.h>

int minimumSwap(char * s1, char * s2){
    //x用来记录s1，s2中x出现的数量，y同理  map用来标记s1，s2哪里元素不相同
    int x = 0, y = 0, len = strlen(s1), i, map[1001] = {0};
    for(i = 0; i < len; i++) {//先遍历一遍s1，s2数组
        if(s1[i] == 'x')
            x++;
        if(s1[i] == 'y')
            y++;
        if(s2[i] == 'x')
            x++;
        if(s2[i] == 'y')
            y++;
        if(s1[i] != s2[i])//当s1，s2元素不同时
            map[i] = 1;//标记
    }
    if(x % 2 != 0 || y % 2 != 0)//当x或者y其中一个是奇数时
        return -1;//没办法使两个字符串相等
    int j = 0;
    char s11[1001] = {'0'};//存放s1，s2不同处的s1的元素
    for(i = 0; i < len; i++) {
        if(map[i] == 1) {//被标记的是不同的
            s11[j++] = s1[i];//存进去
        }
    }
    x = 0;
    y = 0;
    int num = 0;//num是记录交换次数
    for(i = 0; i < j; i++) {//统计s11数组中x，y出现的次数
        if(s11[i] == 'x') {
            x++;
        }
        if(s11[i] == 'y')
            y++;
    }
    int flag = 0;//标记变量

    //剩下的就是此题的规律，当字符串"xx"和"yy"时就是交换一次，当字符串"xy"和"yx"时就是交换两次
    //x，y是偶数或奇数时就分别代表上述两种情况    （交换两次的情况只会有一次）
    if(x % 2 == 0)//判断x的奇偶性
        num = num + x / 2;
    else {
        flag = 1;
        num = num + (x - 1) / 2;
    }
    if(y % 2 == 0)//判断y的奇偶性
        num = num + y / 2;
    else {
        flag = 1;
        num = num + (y - 1) / 2;
    }
    if(flag == 1)//如果x，y有奇数时
        num = num + 2;//交换两次
    return num;
}
