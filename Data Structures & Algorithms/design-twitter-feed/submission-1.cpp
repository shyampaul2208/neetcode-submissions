class Twitter {
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> posts;
    int timer;
public:
    Twitter() {
        timer=0;
    }
    void postTweet(int userId, int tweetId) {
        timer++;
        posts[userId].push_back({timer,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        auto &userFollowers = followers[userId];
        priority_queue<vector<int>> pq;



// pushing current user posts
        if(!posts[userId].empty()){
            int idx = posts[userId].size()-1;
            auto lastPost = posts[userId][idx];
            pq.push({
                lastPost.first,
                lastPost.second,
                userId,
                idx
            });
        }


//add followers posts
        for(auto &ele : userFollowers){
             int lastpostIndex = posts[ele].size()-1;
             if(lastpostIndex>=0){
                auto lastPost = posts[ele][lastpostIndex];
                pq.push({
                    lastPost.first,
                    lastPost.second,
                    ele,
                    lastpostIndex
                    });
             }
        }
  
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            auto top = pq.top();
            pq.pop();
            int tweetId = top[1];
            int authorId= top[2];
            int postIndex = top[3];

            ans.push_back(tweetId);
            
            postIndex--;
            if(postIndex>=0){
                auto previousPost = posts[authorId][postIndex];
                pq.push({
                    previousPost.first,
                    previousPost.second,
                    authorId,
                    postIndex
                });
            }

        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
