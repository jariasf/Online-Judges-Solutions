/*******************************************
 ***Problema: Find Servers That Handled Most Number of Requests
 ***ID: 1606
 ***Juez: LeetCode
 ***Tipo: Priority Queue + Set
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    struct cmp {
        bool operator() ( const pii &a , const pii &b ) {
            return a.first > b.first;
        }
    };     
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& l) {
        priority_queue<pii, vector<pii>, cmp > Q;
        vector<int> cnt(k + 1);  
        set<int> available;
        for( int i = 0 ; i < k ; ++i) available.insert(i);
        
        for( int i = 0 ; i < a.size(); ++i ){
            int val = a[i], cur_id = i % k;
            
            while( !Q.empty() && Q.top().first <= val ){
                available.insert(Q.top().second);
                Q.pop();
            }
            
            if( available.size() == 0 )
                continue;
            
            auto it = available.lower_bound(cur_id);
            if( it == available.end() )
                it = available.begin();
            cur_id = *it;
            
            cnt[cur_id]++;
            available.erase(it);
            Q.push(mp(val + l[i], cur_id));
        }
        
        int maxi = 0;
        for( int i = 0 ; i < k + 1 ; ++i )
            maxi = max(maxi, cnt[i]);
        
        vector<int> res;
        for( int i = 0 ; i < k + 1 ; ++i ){
            if( cnt[i] == maxi )
                res.push_back(i);
        }
        return res;
    }
};
