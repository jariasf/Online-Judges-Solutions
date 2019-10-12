/*******************************************
 ***Problema: Freedom Trail
 ***ID: 1196
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Bottom-Up DP
class Solution {
public:
    int distance(int pos_ring, int pos, int n){
        int minimum = INT_MAX;
        if( pos >= pos_ring ){
            minimum = min( pos - pos_ring, pos_ring + n - pos );
        }else{
            minimum = min( pos_ring - pos, pos + n - pos_ring );
        }
        return minimum;
    }

    /**
     * @param ring: a string
     * @param key: a string
     * @return: return a integer
     */   
    int findRotateSteps(string &ring, string &key){
        vector<vector<int> > hash = vector<vector<int> >(26);
        for( int i = 0 ; i < ring.size(); ++i ){
            hash[ ring[i] - 'a'].push_back(i);
        }        
        
        int n = ring.size(), m = key.size();
        vector<int> dp(n + 1, 1<<30);
        vector<int> last_dp(n + 1, 0);
        vector<int> last_indexes;
        for( int pos_key = 1 ; pos_key <= m; ++pos_key ){
            vector<int> indexes = hash[ key[pos_key - 1] - 'a'];
            for( int i = 0 ; i < indexes.size(); ++i ){
                int pos = indexes[i];
                if( last_indexes.size() == 0 ){
                    dp[pos] = 1 + distance(0, pos, n);
                }else{
                    for( int j = 0 ; j < last_indexes.size(); ++j ){
                        int pos_ring = last_indexes[j];
                        dp[pos] = min( dp[pos], 1 + distance(pos_ring, pos, n) + last_dp[pos_ring]  );
                    }
                }
            }
            last_indexes = indexes;
            last_dp = dp;
            for( int i = 0 ; i < dp.size(); ++i ) dp[i] = 1<<30;
        }
        
        int minimum = 1<<30;
        for( int i = 0 ; i < n ; ++i )
            minimum = min( minimum, last_dp[i]);
        return minimum;
    }
};


// Top-Down DP - Memoization
class Solution {
public:
    string ring, key;
    vector<vector<int> > hash;
    vector<vector<int> > dp;
    
    int distance(int pos_ring, int pos){
        int minimum = INT_MAX, n = ring.size();
        if( pos >= pos_ring ){
            minimum = min( pos - pos_ring, pos_ring + n - pos );
        }else{
            minimum = min( pos_ring - pos, pos + n - pos_ring );
        }
        return minimum;
    }
    
    int minimumSteps(int pos_ring, int pos_key){
        if( pos_key == key.size() )
            return 0;
        if( dp[pos_ring][pos_key] != -1 )
            return dp[pos_ring][pos_key];
        vector<int> indexes = hash[ key[pos_key] - 'a'];
        int minimum = INT_MAX;
        for( int i = 0 ; i < indexes.size(); ++i ){
            int pos = indexes[i];
            minimum = min( minimum, 1 + distance(pos_ring, pos) + minimumSteps(pos, pos_key + 1) );
        }
        return dp[pos_ring][pos_key] = minimum;
    } 

    /**
     * @param ring: a string
     * @param key: a string
     * @return: return a integer
     */     
    int findRotateSteps(string &_ring, string &_key) {
        ring = _ring;
        key = _key;
        hash = vector<vector<int> >(26); 
        for( int i = 0 ; i < ring.size(); ++i )
            hash[ ring[i] - 'a'].push_back(i);
        dp = vector<vector<int> >( ring.size() + 1,vector<int>(key.size() + 1, -1));
        return minimumSteps(0, 0);
    }
};
