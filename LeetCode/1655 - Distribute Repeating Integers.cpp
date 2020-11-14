/*******************************************
 ***Problema: Distribute Repeating Integers
 ***ID: 1655
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming + Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX_VAL 51
int dp[MAX_VAL][(1<<10) + 2];
class Solution {
public:
    vector<int> valid_mask[MAX_VAL];
    int N, M;
    int bitcount( int n ){
        int cnt = 0;
        while( n ){
            n = n & ( n - 1 );
            cnt++;
        }
        return cnt;
    }
    
    bool solve(int pos, int mask){
        if( bitcount(mask) == M ) return true;
        if( pos == N ) return false;
        if( dp[pos][mask] != -1 ) return dp[pos][mask];
        bool res = false;
        res |= solve(pos + 1, mask); 
        if( !res ){
            for( int i = 0 ; i < valid_mask[pos].size(); ++i ){
                int next_mask = valid_mask[pos][i];
                if( !(next_mask & mask) ){
                    res |= solve(pos + 1, next_mask | mask );
                    if( res )
                        return dp[pos][mask] = res;
                }
            }
        }
        return dp[pos][mask] = res;
    }
    
    void precal(vector<int> &values, vector<int> &q){
        int n = q.size();
        for(int k = 0 ; k < values.size(); ++k ){
            for( int i = 1 ; i < 1<<n ; ++i ){
                bool correct = true; 
                int tot = values[k];
                for( int j = 0 ; j < n ; ++j ){
                    if( i & (1<<j) ){
                        if( q[j] <= tot ){
                            tot -= q[j];    
                        }else{
                            correct = false;
                            break;
                        }
                    }
                }
                if( correct ){
                    valid_mask[k].push_back(i);
                }
            }
        }
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> hash;
        vector<int> values;
        for(int val: nums) hash[val]++;
        for(auto it:hash) values.push_back(it.second);
        precal(values, quantity);
        memset(dp , -1, sizeof(dp));
        N = values.size();
        M = quantity.size();
        return solve(0, 0);
    }
};
