class Solution {
public:
    bool divisorGame(int N) {
        //N 为奇数的时候 Alice（先手）必败，N 为偶数的时候 Alice 必胜
        if(N % 2 == 0)
            return true;
        return false;
    }
};
