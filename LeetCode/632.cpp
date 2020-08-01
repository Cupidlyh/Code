class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        //��¼�����е������Сֵ
        int maxx = INT_MIN,minn = INT_MAX;
        unordered_map<int,vector<int>> mp;
        //�������Сֵ�����ҹ�����ϣ��(��:�����е�ֵ��ֵ:���к�)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                maxx = max(maxx,nums[i][j]);
                minn = min(minn,nums[i][j]);
                mp[nums[i][j]].push_back(i);
            }
        }
        //��ǰ�������ڵ���˵���Ҷ˵�
        int nowleft = minn,nowright = minn - 1;
        //��������Ҷ˵�
        int resleft = minn,resright = maxx;
        //��¼ÿ�����кų��ֵĴ���
        vector<int> amo(n,0);
        int qua = 0;//��¼���г��ֵĸ���
        while(nowright < maxx) {
            nowright++;//�Ҷ˵�����
            if(mp.count(nowright)) {//�Ҷ˵��ڹ�ϣ���д���
                for(int i = 0; i < mp[nowright].size(); i++) {//������ϣ��
                    amo[mp[nowright][i]]++;//���кų��ֵĴ�����1
                    if(amo[mp[nowright][i]] == 1) {//������кų��ֹ�һ��
                        qua++;//���и�����1
                    }
                }
                while(qua == n) {//���и�������n(ÿ����������һ�������ڵ�ǰ������)
                    if(resright - resleft > nowright - nowleft) {//�������
                        resright = nowright;
                        resleft = nowleft;
                    }
                    if(mp.count(nowleft)) {//��˵��ڹ�ϣ���д���
                        for(int i = 0; i < mp[nowleft].size(); i++) {//������ϣ��
                            amo[mp[nowleft][i]]--;//���кų��ֵĴ�����1
                            if(amo[mp[nowleft][i]] == 0) {//������кŴ���Ϊ0
                                qua--;//���и�����1
                            }
                        }
                    }
                    nowleft++;//��˿�����
                }
            }
        }
        return {resleft,resright};
    }
};
