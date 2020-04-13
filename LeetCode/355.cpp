class Twitter {

    struct Node {
        int UserId;//用户号
        int TweetId;//推文号
    };

    int time;//推文发出的时间
    unordered_map<int, Node> tweetTime;//记录当前time发送推文的userId和tweetId
    unordered_map<int, unordered_set<int>> user;//记录每个用户关注的用户

public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        user[userId].insert(userId);//题目默认自己关注自己
        tweetTime[time].UserId = userId;
        tweetTime[time].TweetId = tweetId;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int i,num = 0;
        for(i = time; i >= 1; i--) {//按时间顺序显示
            if(tweetTime.find(i) != tweetTime.end()) {
                if(user[userId].find(tweetTime[i].UserId) != user[userId].end()) {//判断此时刻推文的发送者是否被userId关注
                    num++;
                    ans.push_back(tweetTime[i].TweetId);
                }
            }
            if(num >= 10)//只检索十条
                break;
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)//自己不可取消关注自己（自己只能取关别人）
            user[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
