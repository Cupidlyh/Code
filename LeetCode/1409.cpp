class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>ans;
        list<int>l;//����
        list<int>::iterator it;//������
        int i;
        for(i = 1; i <= m; i++)//1��m�浽������
            l.push_back(i);
        for(i = 0; i < queries.size(); i++) {
            int bit = 0;//��¼����Ԫ�ص��±�
            for(it = l.begin(); it != l.end(); it++) {//��������
                if(*it == queries[i]) {//�ҵ�Ԫ��
                    ans.push_back(bit);//�±��������
                    l.push_front(*it);//��ǰԪ�طŵ�����ͷ��
                    l.erase(it);//�����˵�����ָ��λ�õ�Ԫ��
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
