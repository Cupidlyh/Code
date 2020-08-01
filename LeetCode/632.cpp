class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        //记录区间中的最大最小值
        int maxx = INT_MIN,minn = INT_MAX;
        unordered_map<int,vector<int>> mp;
        //找最大最小值，并且构建哈希表(键:序列中的值，值:序列号)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                maxx = max(maxx,nums[i][j]);
                minn = min(minn,nums[i][j]);
                mp[nums[i][j]].push_back(i);
            }
        }
        //当前滑动窗口的左端点和右端点
        int nowleft = minn,nowright = minn - 1;
        //结果的左右端点
        int resleft = minn,resright = maxx;
        //记录每个序列号出现的次数
        vector<int> amo(n,0);
        int qua = 0;//记录序列出现的个数
        while(nowright < maxx) {
            nowright++;//右端点右移
            if(mp.count(nowright)) {//右端点在哈希表中存在
                for(int i = 0; i < mp[nowright].size(); i++) {//遍历哈希表
                    amo[mp[nowright][i]]++;//序列号出现的次数加1
                    if(amo[mp[nowright][i]] == 1) {//如果序列号出现过一次
                        qua++;//序列个数加1
                    }
                }
                while(qua == n) {//序列个数等于n(每个序列至少一个数字在当前窗口内)
                    if(resright - resleft > nowright - nowleft) {//结果更新
                        resright = nowright;
                        resleft = nowleft;
                    }
                    if(mp.count(nowleft)) {//左端点在哈希表中存在
                        for(int i = 0; i < mp[nowleft].size(); i++) {//遍历哈希表
                            amo[mp[nowleft][i]]--;//序列号出现的次数减1
                            if(amo[mp[nowleft][i]] == 0) {//如果序列号次数为0
                                qua--;//序列个数减1
                            }
                        }
                    }
                    nowleft++;//左端口右移
                }
            }
        }
        return {resleft,resright};
    }
};
