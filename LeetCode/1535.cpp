class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxx = 0;
        list<int> num;
        //找出arr数组的最大值(如果下面的比较到了最大值，那最大值一定是赢家)
        for(int i = 0; i < arr.size(); i++) {
            maxx = max(maxx,arr[i]);
            num.push_back(arr[i]);
        }
        //记录每个数字获胜的次数
        unordered_map<int,int> mp;
        //从链表中取出的第一，二个数字
        int first,second;
        //模拟比较过程
        while(true) {
            first = num.front();
            num.pop_front();
            //是最大值一定是赢家
            if(first == maxx)
                return first;
            second = num.front();
            num.pop_front();
            if(second == maxx)
                return second;
            if(mp.find(first) == mp.end())
                mp[first] = 0;
            if(mp.find(second) == mp.end())
                mp[second] = 0;
            //模拟比较过程
            if(first > second) {
                mp[first]++;
                num.push_front(first);
                num.push_back(second);
                if(mp[first] >= k)
                    return first;
            }
            else {
                mp[second]++;
                num.push_front(second);
                num.push_back(first);
                if(mp[second] >= k)
                    return second;
            }
        }
        return 0;
    }
};
