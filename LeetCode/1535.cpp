class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxx = 0;
        list<int> num;
        //�ҳ�arr��������ֵ(�������ıȽϵ������ֵ�������ֵһ����Ӯ��)
        for(int i = 0; i < arr.size(); i++) {
            maxx = max(maxx,arr[i]);
            num.push_back(arr[i]);
        }
        //��¼ÿ�����ֻ�ʤ�Ĵ���
        unordered_map<int,int> mp;
        //��������ȡ���ĵ�һ����������
        int first,second;
        //ģ��ȽϹ���
        while(true) {
            first = num.front();
            num.pop_front();
            //�����ֵһ����Ӯ��
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
            //ģ��ȽϹ���
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
