#include <stdio.h>
#include <stdlib.h>

int maxProduct(char** words, int wordsSize) {//传进来的是一个字符的二维数组
	int i, j, maxProduct = 0, m, n, flag = 0;
	for (i = 0; i < wordsSize; i++) {
		for (j = i + 1; j < wordsSize; j++) {
			n = 0;
			m = 0;
			flag = 0;
			int counts[26] = {};//这个数组用来打表，初值为0，字母有26个，所以开辟这么大的
			while (words[i][n]!= '\0') {
				counts[words[i][n]- 'a']=1;//如果字母在第i行的字符串中出现，打表为1
                n++;//第i行字符串的长度
			}
			while (words[j][m]!= '\0') {
				if (counts[words[j][m] - 'a']) {//如果counts在字母a的位置为1，就在i中出现过
                    flag = 1;
					break;//不符合题意，跳出循环
				}
				else {
					m++;//一直都不相同的话，m就是第j个字符串的长度
				}
			}
			if (flag == 0)//flag=0，意味着比较到了最后，没有相同的字母
				if (maxProduct < m * n)
					maxProduct = m * n;
		}
	}
	return maxProduct;
}

