class Solution {
public:
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>,hash_pair> s;//用来标记点走过的坐标
        int x = 0,y = 0;
        s.insert({x,y});
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == 'N') {
                y += 1;
                if(s.find({x,y}) != s.end())
                    return true;
                s.insert({x,y});
            }
            else if(path[i] == 'S') {
                y -= 1;
                if(s.find({x,y}) != s.end())
                    return true;
                s.insert({x,y});
            }
            else if(path[i] == 'E') {
                x += 1;
                if(s.find({x,y}) != s.end())
                    return true;
                s.insert({x,y});
            }
            else if(path[i] == 'W') {
                x -= 1;
                if(s.find({x,y}) != s.end())
                    return true;
                s.insert({x,y});
            }
        }
        return false;
    }
};
