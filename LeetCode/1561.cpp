class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());//����
        //����ÿ��ȡn��Ӳ��,�ܹ�3*n��,��С�����ź�����
        //Bob����ȡ��С��һ�ѣ�����ǰn��Bobȡ��
        //ֻʣ��2*n��Ӳ�ң����㾡���ܻ�����Ӳ����Ŀ��Alice��ȡ��Ӳ������
        //ʣ�½����������2*n��Ӳ�ҷֳ�n�飬ÿ��2����Aliceȡ�߶����һ����ʣ�µĸ���
        //��Ϊ��Ҫ�󾡿��ܴ�������ÿ��ȡ�ľ���ʣ��ĵڶ����
        //(1,2,3,4,5,6,7,8,9),Bobȡ��(1,2,3),ʣ(4,5|6,7|8,9),��ȡ�ڶ���,��(4,6,8),Aliceȡ���(5,7,9)
        int res = 0;
        int num = piles.size() / 3;
        for(int i = num; i < piles.size(); i += 2)
            res += piles[i];
        return res;
    }
};
