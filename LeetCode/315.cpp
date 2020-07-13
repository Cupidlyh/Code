class Solution {
public:
    vector<int> c;//树状数组
    vector<int> a;//nums离散化处理后成a数组

    void Init(int len) {
        //对树状数组设置大小
        c.resize(len, 0);
    }

    void Discretization(vector<int>& nums) {
        //拷贝数组
        a.assign(nums.begin(), nums.end());
        //对数组进行排序
        sort(a.begin(), a.end());
        //对数组进行去重
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int getId(int x) {
        //lower_bound()返回值是一个迭代器,返回指向大于等于x的第一个值的位置
        //lower_bound()函数内部就是二分查找
        //加一的目的是因为树状数组是从下标1的位置开始存储
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    //下面这三个函数就是树状数组-单点更新区间查询的模板
    int lowbit(int x) {
        return x&(-x);
    }

    int getsum(int i) {//求a[1]到a[i]的和(包含a[i])
        int res = 0;
        while(i > 0)
        {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }

    void updata(int i) {//在i位置加上k(此题k固定为1)（此函数只更改树状数组的值，若要更改原数组的值需要在主函数中实现）
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
        reverse(res.begin(), res.end());//翻转
        return res;
    }
};
