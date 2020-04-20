class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
            return 0;
        int s1cnt = 0, index = 0, s2cnt = 0;
        //ע��s2Ҫ�ӵ�index���ַ���ʼƥ��
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            //���Ƕ����һ��s1�������ܲ����ҵ�ѭ����(����ԭ��)
            s1cnt++;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == s2.length()) {
                        s2cnt++;
                        index = 0;
                    }
                }
            }
            //��û���ҵ�ѭ���ڣ����е�s1��������
            if (s1cnt == n1)
                return s2cnt / n2;
            //������֮ǰ��index����ʾ�ҵ���ѭ����
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // ǰ s1cnt' �� s1 ������ s2cnt' �� s2
                pre_loop = {s1cnt_prime, s2cnt_prime};
                // �Ժ��ÿ (s1cnt - s1cnt') �� s1 ������ (s2cnt - s2cnt') �� s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            }
            else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        // ans �洢���� S1 ������ s2 �����������ǵ�֮ǰ�� pre_loop �� in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 ��ĩβ��ʣ��һЩ s1�����Ǳ�������ƥ��
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == s2.length()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        //S1����ans��s2����ô�Ͱ���ans / n2��S2
        return ans / n2;
    }
};
