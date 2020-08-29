class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());//排序
        //假设每人取n个硬币,总共3*n个,从小到大排好序了
        //Bob总是取最小的一堆，所以前n个Bob取走
        //只剩下2*n个硬币，而你尽可能获得最大硬币数目，Alice会取走硬币最多的
        //剩下解决的问题是2*n个硬币分成n组，每组2个，Alice取走多的那一个，剩下的给你
        //因为你要求尽可能大，所以你每次取的就是剩余的第二大的
        //(1,2,3,4,5,6,7,8,9),Bob取走(1,2,3),剩(4,5|6,7|8,9),你取第二大,即(4,6,8),Alice取最大(5,7,9)
        int res = 0;
        int num = piles.size() / 3;
        for(int i = num; i < piles.size(); i += 2)
            res += piles[i];
        return res;
    }
};
