class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size(),m,i,bit = (n - 1) / 2;
        sort(arr.begin(),arr.end());//排序
        m = arr[bit];//中位数
        vector<int>diff,res;
        //diff数组存储arr中的元素与中位数差值的绝对值
        for(i = 0; i < n; i++) {
            diff.push_back(abs(arr[i] - m));
        }
        int left = 0,right = n - 1;
        //那两个条件都是根据与中位数之差的绝对值来判断数字强度
        //从小到大排好序的数组，与中位数之差的绝对值由两边向内减少
        //所以从两边开始比较和判断
        while(k) {
            //条件|arr[i] - m| == |arr[j] - m|，且 arr[i] > arr[j]
            if(diff[left] == diff[right]) {
                if(arr[left] > arr[right]) {
                    res.push_back(arr[left++]);
                }
                else {
                    res.push_back(arr[right--]);
                }
            }
            //条件|arr[i] - m| > |arr[j] - m|
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
