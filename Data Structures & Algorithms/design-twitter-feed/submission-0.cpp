class Twitter {
    unordered_map<int, unordered_set<int>> followers;

    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> posts;

    int timer;

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        timer++;
        posts[userId].push_back({timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {timestamp, tweetId, userId, postIndex}
        priority_queue<vector<int>> pq;

        // Add user's own latest tweet
        if (!posts[userId].empty()) {
            int idx = posts[userId].size() - 1;

            auto lastPost = posts[userId][idx];

            pq.push({
                lastPost.first,
                lastPost.second,
                userId,
                idx
            });
        }

        // Add latest tweet of every followee
        for (int followeeId : followers[userId]) {

            if (followeeId == userId)
                continue;

            int lastPostIndex = posts[followeeId].size() - 1;

            if (lastPostIndex >= 0) {

                auto lastPost = posts[followeeId][lastPostIndex];

                pq.push({
                    lastPost.first,
                    lastPost.second,
                    followeeId,
                    lastPostIndex
                });
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int authorId = top[2];
            int postIndex = top[3];

            ans.push_back(tweetId);

            // Move to previous tweet from same user
            postIndex--;

            if (postIndex >= 0) {

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