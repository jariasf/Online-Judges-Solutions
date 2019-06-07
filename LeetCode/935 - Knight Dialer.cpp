/*******************************************
 ***Problema: Knight Dialer
 ***ID: 935
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pb push_back
#define MOD 1000000007
typedef long long LL;
class Solution {
public:
    vector<int> ady[10];
    void init(){
        for(int i = 0 ; i < 10 ; ++i )ady[i].clear();
        ady[0].pb(4); ady[0].pb(6);
        ady[1].pb(6); ady[1].pb(8);
        ady[2].pb(7); ady[2].pb(9);
        ady[3].pb(4); ady[3].pb(8);
        ady[4].pb(3); ady[4].pb(0); ady[4].pb(9);
        ady[6].pb(0); ady[6].pb(1); ady[6].pb(7);
        ady[7].pb(2); ady[7].pb(6);
        ady[8].pb(1); ady[8].pb(3);
        ady[9].pb(2); ady[9].pb(4);
    }
    
    vector<vector<int> > dp;
    LL solve(int digit, int N){
        if( N == 0 ){
            return 1;
        }
        
        if( dp[digit][N] != -1 ) return dp[digit][N];
        
        LL result = 0;
        for( int i = 0 ; i < ady[digit].size(); ++i ){
            result = result + solve(ady[digit][i], N - 1) % MOD;
            result %= MOD;
        }
        return dp[digit][N] = result;
    }
    
    int knightDialer(int N) {
        
        init();
        dp = vector<vector<int> >(10, vector<int>(N + 5, -1));
        LL result = 0;
        for( int i = 0; i <= 9 ; ++i ) result = (result % MOD + solve(i, N - 1) % MOD) % MOD;
        return result;
    }
};
