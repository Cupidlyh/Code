class Solution {
public:
    vector<int> c;//��״����
    vector<int> a;//nums��ɢ��������a����

    void Init(int len) {
        //����״�������ô�С
        c.resize(len, 0);
    }

    void Discretization(vector<int>& nums) {
        //��������
        a.assign(nums.begin(), nums.end());
        //�������������
        sort(a.begin(), a.end());
        //���������ȥ��
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int getId(int x) {
        //lower_bound()����ֵ��һ��������,����ָ����ڵ���x�ĵ�һ��ֵ��λ��
        //lower_bound()�����ڲ����Ƕ��ֲ���
        //��һ��Ŀ������Ϊ��״�����Ǵ��±�1��λ�ÿ�ʼ�洢
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    //��������������������״����-������������ѯ��ģ��
    int lowbit(int x) {
        return x&(-x);
    }

    int getsum(int i) {//��a[1]��a[i]�ĺ�(����a[i])
        int res = 0;
        while(i > 0)
        {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }

    void updata(int i) {//��iλ�ü���k(����k�̶�Ϊ1)���˺���ֻ������״�����ֵ����Ҫ����ԭ�����ֵ��Ҫ����������ʵ�֣�
        while(i < c.size())
        {
            c[i] += 1;
            i += lowbit(i);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        Init(nums.size() + 5);
        Discretization(nums);
        for(int i = nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            updata(id);
            res.push_back(getsum(id - 1));
        }
        reverse(res.begin(), res.end());//��ת
        return res;
    }
};
