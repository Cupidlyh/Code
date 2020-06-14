class BrowserHistory {
public:
    vector<string>str;//存储网址信息
    int left,right;//left记录当前访问的位置，right记录visit函数到达的网址的下标
    BrowserHistory(string homepage) {
        str.resize(5005);//设置大小
        left = -1;
        str[++left] = homepage;
        right = left + 1;
    }

    void visit(string url) {//存储网址
        str[++left] = url;
        right = left + 1;
    }

    string back(int steps) {
        string res;
        if(steps >= left) {//步数大于可回退步数
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
        if(steps >= right - left - 1) {//步数大于可前进步数
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
