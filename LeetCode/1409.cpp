class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>ans;
        list<int>l;//链表
        list<int>::iterator it;//迭代器
        int i;
        for(i = 1; i <= m; i++)//1到m存到链表中
            l.push_back(i);
        for(i = 0; i < queries.size(); i++) {
            int bit = 0;//记录链表元素的下标
            for(it = l.begin(); it != l.end(); it++) {//遍历链表
                if(*it == queries[i]) {//找到元素
                    ans.push_back(bit);//下标存进结果中
                    l.push_front(*it);//当前元素放到链表头部
                    l.erase(it);//擦除此迭代器指向位置的元素
                    break;
                }
                else {
                    bit++;
                }
            }
        }
        return ans;
    }
};
