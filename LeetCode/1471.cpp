class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size(),m,i,bit = (n - 1) / 2;
        sort(arr.begin(),arr.end());//����
        m = arr[bit];//��λ��
        vector<int>diff,res;
        //diff����洢arr�е�Ԫ������λ����ֵ�ľ���ֵ
        for(i = 0; i < n; i++) {
            diff.push_back(abs(arr[i] - m));
        }
        int left = 0,right = n - 1;
        //�������������Ǹ�������λ��֮��ľ���ֵ���ж�����ǿ��
        //��С�����ź�������飬����λ��֮��ľ���ֵ���������ڼ���
        //���Դ����߿�ʼ�ȽϺ��ж�
        while(k) {
            //����|arr[i] - m| == |arr[j] - m|���� arr[i] > arr[j]
            if(diff[left] == diff[right]) {
                if(arr[left] > arr[right]) {
                    res.push_back(arr[left++]);
                }
                else {
                    res.push_back(arr[right--]);
                }
            }
            //����|arr[i] - m| > |arr[j] - m|
            else {
                if(diff[left] > diff[right]) {
                    res.push_back(arr[left++]);
                }
                else {
                    res.push_back(arr[right--]);
                }
            }
            k--;
        }
        return res;
    }
};
