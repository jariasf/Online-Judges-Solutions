/*******************************************
 ***Problem: Tweet Counts Per Frequency
 ***ID: 1348
 ***Judge: LeetCode
 ***Type: Hashing + MultiSet|Map
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Using map
class TweetCounts {
public:
    unordered_map<string, map<int, int> > hash;

    TweetCounts() {
        hash.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        hash[ tweetName ][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if( hash.find(tweetName) == hash.end() ) return vector<int>();
        
        int max_range = 60;
        if( freq == "hour") max_range = 3600;
        else if( freq == "day" ) max_range = 86400;

        int buckets = (endTime - startTime)/max_range + 1;
        vector<int> res(buckets);

        map<int, int> &mp = hash[tweetName];
        map<int, int>::iterator low = mp.lower_bound(startTime);
        for(; low != mp.end() && low -> first <= endTime ; ++low ){
            int pos = low -> first - startTime;
            int cnt = low -> second;
            int bucket_pos = pos / max_range;
            res[bucket_pos] += cnt;
        }
        
        return res;
    }
};


// Using multiset
class TweetCounts {
public:
    unordered_map<string, multiset<int> > hash;
    TweetCounts() {
        hash.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        hash[ tweetName ].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if( hash.find(tweetName) == hash.end() ) return vector<int>();
        
        int max_range = 60;
        if( freq == "hour") max_range = 3600;
        else if( freq == "day" ) max_range = 86400;

        int buckets = (endTime - startTime)/max_range + 1;
        vector<int> res(buckets);
        
        multiset<int> &mp = hash[tweetName];
        multiset<int>::iterator low = mp.lower_bound(startTime);
        
        for(; low != mp.end() && *low <= endTime ; ++low ){
            int pos = *low - startTime;
            int bucket_pos = pos / max_range;
            res[bucket_pos]++;
        }

        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

// Some tests
/*
["TweetCounts","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency","recordTweet"]
[[],["tweet0",19],["tweet1",34],["tweet2",36],["tweet3",59],["tweet4",64],["tweet2",48],["tweet4",21],["tweet2",44],["minute","tweet1",59,9302],["tweet2",74],["minute","tweet4",64,2783],["tweet2",16]]
["TweetCounts","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","recordTweet","recordTweet","recordTweet"]
[[],["tweet0",78],["tweet1",7],["tweet2",61],["tweet3",0],["tweet4",20],["minute","tweet2",78,5374],["tweet4",39],["tweet4",15],["tweet1",37]]
["TweetCounts","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency"]
[[],["tweet0",13],["tweet1",16],["tweet2",12],["tweet3",18],["tweet4",82],["tweet3",89],["day","tweet0",89,9471],["hour","tweet3",13,4024]]
["TweetCounts","recordTweet","recordTweet","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","recordTweet","recordTweet","recordTweet","recordTweet"]
[[],["tweet0",33],["tweet1",89],["tweet2",99],["tweet3",53],["tweet4",3],["hour","tweet0",89,3045],["tweet0",28],["tweet0",91],["tweet0",9],["tweet1",6]]
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]
*/
