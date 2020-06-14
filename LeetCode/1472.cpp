class BrowserHistory {
public:
    vector<string>str;//�洢��ַ��Ϣ
    int left,right;//left��¼��ǰ���ʵ�λ�ã�right��¼visit�����������ַ���±�
    BrowserHistory(string homepage) {
        str.resize(5005);//���ô�С
        left = -1;
        str[++left] = homepage;
        right = left + 1;
    }

    void visit(string url) {//�洢��ַ
        str[++left] = url;
        right = left + 1;
    }

    string back(int steps) {
        string res;
        if(steps >= left) {//�������ڿɻ��˲���
            res = str[0];
            left = 0;
        }
        else {
            left = left - steps;
            res = str[left];
        }
        return res;
    }

    string forward(int steps) {
        string res;
        if(steps >= right - left - 1) {//�������ڿ�ǰ������
            res = str[right - 1];
            left = right - 1;
        }
        else {
            left = left + steps;
            res = str[left];
        }
        return res;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
