class Solution {
public:
    int minFlips(string target) {
        //�Ƚ������ַ��Ƿ���ͬ����ͬ�ͼ�����һ��������λ����ĸҲҪ�ж��Ƿ�Ϊ'1'��Ҫ���ж���ķ�ת��
        int step = 0;
        if(target[0] == '1')
            step++;
        for(int i = 1; i < target.length(); i++) {
            if(target[i] != target[i - 1])
                step++;
        }
        return step;
    }
};
