class Solution {
public:
    //�ж�����arr��[s,e)��Χ���Ƿ���K���ַ���[s,s+m)���
    bool istrue(vector<int>& arr, int m,int s,int e) {
        for (int i = s + m; i < e; i++) {
            if(arr[i] != arr[i - m])
                return false;
        }
        return true;
    }


    bool containsPattern(vector<int>& arr, int m, int k) {
        int p = arr.size();
        int n = m * k;
        if (p - n < 0)
            return false;
        //����ö��
        for (int i = 0; i <= p - n; i++) {
            int sta = i;
            int end = i + n;
            if (istrue(arr,m,sta,end)) {
                return true;
            }
        }
        return false;
    }
};
