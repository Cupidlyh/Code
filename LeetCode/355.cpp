class Twitter {

    struct Node {
        int UserId;//�û���
        int TweetId;//���ĺ�
    };

    int time;//���ķ�����ʱ��
    unordered_map<int, Node> tweetTime;//��¼��ǰtime�������ĵ�userId��tweetId
    unordered_map<int, unordered_set<int>> user;//��¼ÿ���û���ע���û�

public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        user[userId].insert(userId);//��ĿĬ���Լ���ע�Լ�
        tweetTime[time].UserId = userId;
        tweetTime[time].TweetId = tweetId;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int i,num = 0;
        for(i = time; i >= 1; i--) {//��ʱ��˳����ʾ
            if(tweetTime.find(i) != tweetTime.end()) {
                if(user[userId].find(tweetTime[i].UserId) != user[userId].end()) {//�жϴ�ʱ�����ĵķ������Ƿ�userId��ע
                    num++;
                    ans.push_back(tweetTime[i].TweetId);
                }
            }
            if(num >= 10)//ֻ����ʮ��
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
        if(followerId != followeeId)//�Լ�����ȡ����ע�Լ����Լ�ֻ��ȡ�ر��ˣ�
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
