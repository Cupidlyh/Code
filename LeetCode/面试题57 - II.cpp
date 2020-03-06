#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int>temp;
        vector<vector<int>>res;
        int left = 1;//��ָ��
        int right = 1;//��ָ��
        int sum = 1;//�ͣ�����ָ�붼������
        while(left <= target / 2) {//��Ϊ�����������������������ָ��С��target��һ�룩
            if(sum < target) {//����С��target
                right++;//��ָ���һ
                sum = sum + right;//���
            }
            else if(sum > target) {//���ʹ���target
                sum = sum - left;//���
                left++;//��ָ���һ
            }
            else {//���͵���target
                for(int i = left; i <= right; i++) {
                    temp.push_back(i);//��������temp
                }
                res.push_back(temp);//��temp���res
                temp.clear();//���temp
                //������һ�����
                sum = sum - left;
                left++;
            }
        }
        return res;
    }
};
