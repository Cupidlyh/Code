class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int i,maxx = 0;
        for(i = 0; i < candies.size(); i++)
            maxx = max(maxx,candies[i]);
        for(i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= maxx)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
