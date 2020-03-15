/*******************************************
 ***Problem: Maximum Performance of a Team
 ***ID: 1383
 ***Judge: LeetCode
 ***Type: Sorting + Priority Queue
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9+7;
    typedef long long LL;
    #define pii pair<LL,LL>
    #define mp make_pair
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> v;
        for( int i = 0 ; i < n ; ++i )
            v.push_back(mp(efficiency[i], speed[i])); 
        sort(v.begin(), v.end());        
        reverse(v.begin(), v.end());        
        priority_queue<int, vector<int>, greater<int> > Q;
        LL sum = 0;
        LL res = 0;
        
        for( int i = 0 ; i < k ; ++i ){
            sum = (sum + v[i].second);
            Q.push(v[i].second);
            res = max(res, sum * v[i].first);
        }
        
        for( int i = k ; i < n ; ++i ){
            Q.push(v[i].second);
            sum = (sum + v[i].second);
            sum = (sum - Q.top());
            Q.pop();
            res = max( res, sum * v[i].first );
        }
        return res % MOD;
    }
};
