#include <stdio.h>
#include <stdlib.h>

int maxProduct(char** words, int wordsSize) {//����������һ���ַ��Ķ�ά����
	int i, j, maxProduct = 0, m, n, flag = 0;
	for (i = 0; i < wordsSize; i++) {
		for (j = i + 1; j < wordsSize; j++) {
			n = 0;
			m = 0;
			flag = 0;
			int counts[26] = {};//����������������ֵΪ0����ĸ��26�������Կ�����ô���
			while (words[i][n]!= '\0') {
				counts[words[i][n]- 'a']=1;//�����ĸ�ڵ�i�е��ַ����г��֣����Ϊ1
                n++;//��i���ַ����ĳ���
			}
			while (words[j][m]!= '\0') {
				if (counts[words[j][m] - 'a']) {//���counts����ĸa��λ��Ϊ1������i�г��ֹ�
                    flag = 1;
					break;//���������⣬����ѭ��
				}
				else {
					m++;//һֱ������ͬ�Ļ���m���ǵ�j���ַ����ĳ���
				}
			}
			if (flag == 0)//flag=0����ζ�űȽϵ������û����ͬ����ĸ
				if (maxProduct < m * n)
					maxProduct = m * n;
		}
	}
	return maxProduct;
}

