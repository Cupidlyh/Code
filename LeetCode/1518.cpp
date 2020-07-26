class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //empty表示空瓶子数，bott表示可以用空瓶子换几瓶酒，res代表结果
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
