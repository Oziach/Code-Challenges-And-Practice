struct Node{
    list<pair<int,int>>::iterator it;
    list<pair<int,int>>::iterator listEnd;
};

class Comp{
public:
    bool operator()(Node a, Node b){
        return a.it->first < b.it->first;
    }
};

class Twitter {
private:
unordered_map<int, unordered_set<int>> follows;
unordered_map<int, list<pair<int,int>>> tweetsMadeBy; //{time, tweetId}
int time;
int numberOfTweetsInFeed;

public:
    Twitter() {
        time = 0;
        numberOfTweetsInFeed = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsMadeBy[userId].push_front({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        follows[userId].insert(userId);
        vector<int> feed;
        
        priority_queue<Node, vector<Node>, Comp> minHeap;

        for(int follow : follows[userId]){
            if(tweetsMadeBy[follow].empty()){continue;} //add only if followed account has made any tweets

            minHeap.push({tweetsMadeBy[follow].begin(), tweetsMadeBy[follow].end()});
        }

        for(int i = 0; i < numberOfTweetsInFeed; i++){
            if(minHeap.empty()){break;}
            auto listNode = minHeap.top();
            minHeap.pop();

            feed.push_back(listNode.it->second);
  
            listNode.it++;

            if(listNode.it != listNode.listEnd){
                minHeap.push(listNode);
            }
        }
        cout << endl;

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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