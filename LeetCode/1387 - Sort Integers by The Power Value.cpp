/*******************************************
 ***Problem: Sort Integers by The Power Value
 ***ID: 1387
 ***Judge: LeetCode
 ***Type: Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int steps(int n){
        int cnt = 0;
        while(n > 1){
            if( n & 1 ) n = 3 * n + 1;
            else n /= 2;
            cnt++;
        }
        return cnt;
    }

    int getKth(int lo, int hi, int k) {
        vector<pii> v;
        for( int i = lo ; i <= hi ; ++i )
            v.push_back(mp(steps(i), i));
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};

// Using DP (more expensive)
class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    typedef long long LL;
    unordered_map<LL, int> dp;
    int steps(LL n){
        if( n == 1 ) return 0;
        if( dp.find(n) != dp.end() ) return dp[n];
        if( n & 1 ){
            dp[n] = 1 + steps(3 * n + 1);    
        }else
            dp[n] = 1 + steps(n/2);
        return dp[n];
    }

    int getKth(int lo, int hi, int k) {
        dp.clear();
        vector<pii> v;
        for( int i = lo ; i <= hi ; ++i )
            v.push_back(mp(steps(i), i));
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};
