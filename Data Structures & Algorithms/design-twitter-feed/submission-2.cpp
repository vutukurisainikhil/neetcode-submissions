class Twitter {
    int count;  // global timestamp; increments with every post (newer = larger)
    // userId -> list of {timestamp, tweetId}, in post order (oldest first, newest last)
    unordered_map<int, vector<vector<int>>> tweetMap;
    // userId -> set of followee userIds
    unordered_map<int, set<int>> followMap;
public:
    Twitter() : count(0) {}
    
    // Post a tweet. Timestamp from global counter ensures global ordering.
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    // Get up to 10 most recent tweets from user + their followees, in newest-first order.
    // Strategy: k-way merge across followees' tweet lists, pulling latest each time.
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        // Max-heap of {timestamp, tweetId, ownerId, indexInOwnerList}.
        // Largest timestamp comes out first → newest tweet first.
        priority_queue<vector<int>> maxHeap;
        
        // Make sure user sees their own tweets too.
        followMap[userId].insert(userId);
        
        // Seed the heap with each followee's most recent tweet.
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                const auto& tweets = tweetMap[followeeId];
                int idx = tweets.size() - 1;  // newest tweet's index
                maxHeap.push({tweets[idx][0], tweets[idx][1], followeeId, idx});
            }
        }
        
        // Pull the newest tweet from the heap, then push the next-newest from that owner.
        // Continue until 10 tweets collected or heap exhausted.
        while (!maxHeap.empty() && res.size() < 10) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            res.push_back(top[1]);  // tweetId
            int ownerId = top[2]; // followeeId
            int idx = top[3]; // idx
            if (idx > 0) {
                // Push the previous (older) tweet from this owner.
                const auto& prev = tweetMap[ownerId][idx - 1];
                maxHeap.push({prev[0], prev[1], ownerId, idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};