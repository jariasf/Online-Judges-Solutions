/*******************************************
 ***Problema: Knight Dialer
 ***ID: 1707
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param N: N
     * @return: return the number of distinct numbers can you dial in this manner mod 1e9+7
     */
    #define MAX 10
    #define MAX_JUMPS 5005
    #define MOD 1000000007 
    typedef long long LL;
    vector<vector<LL> > dp;
    vector<int> adj[MAX];
     
    void init(){
        adj[0] = {4 ,6};
        adj[1] = {6, 8};
        adj[2] = {7, 9};
        adj[3] = {4, 8};
        adj[4] = {0, 3, 9};
        adj[6] = {0, 1, 7};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};
    } 
    
    LL counting(int digit, int jumps){
        if( jumps == 0 )
            return 1;
        
        if( dp[digit][jumps] != -1 )
            return dp[digit][jumps];
            
        LL counts = 0;
        for( int i = 0 ; i < adj[digit].size(); ++i ){
            int next_digit = adj[digit][i];
            counts += counting(next_digit, jumps - 1);
            counts %= MOD;
        }
        return dp[digit][jumps] = counts;
    }
    
     
    int knightDialer(int N) {
        init();
        dp = vector<vector<LL> >(MAX, vector<LL>(MAX_JUMPS, -1));
        LL total_count = 0;
        for( int i = 0 ; i < MAX ; ++i ){
            total_count += counting(i, N - 1);
            total_count %= MOD;
        }
        return total_count;
    }
};
