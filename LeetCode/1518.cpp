class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //empty��ʾ��ƿ������bott��ʾ�����ÿ�ƿ�ӻ���ƿ�ƣ�res������
        int empty = numBottles,bott = 0,res = numBottles;
        while(empty >= numExchange) {
            bott = empty / numExchange;
            empty = empty - numExchange * bott;
            res += bott;
            empty += bott;
        }
        return res;
    }
};
