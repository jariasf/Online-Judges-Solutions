/*******************************************
 ***Problema: Find the Shortest Superstring
 ***ID: 943
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 13
    vector<string> v;
    int dp[MAX][1<<MAX];
    int dp_overlap[MAX][MAX];
    
    
    int overlap(int i, int j){
        string s1 = v[i], s2 = v[j];
        int len = min(s1.size(), s2.size());
        for( int i = 0 ; i < len ; ++i ){
            string suffix = s1.substr(s1.size() - len + i);
            string preffix = s2.substr(0, len - i);
            if( suffix == preffix ){
                return suffix.size();
            }
        }
        return 0;
    }
    
    void precal(){
        for( int i = 0 ; i < v.size(); ++i ){
            for( int j = 0 ; j < v.size(); ++j ){
                dp_overlap[i][j] = overlap(i, j);
            }
        }
    }
    
    int bitcount(int n){
        int ones = 0;
        while(n){
            ones++;
            n = n & (n - 1);
        }
        return ones;
    }
    
    int solve(int pos, int mask){
        if( bitcount(mask) == v.size() ){
            return dp[pos][mask] = v[pos].size();
        }
        
        if( pos >= 0 && dp[pos][mask] != -1 ){
            return dp[pos][mask];
        }
        
        int len = 1<<30;
        for( int i = 0 ; i < v.size(); ++i ){
            if( !(mask & (1<<i)) ){
                if( pos >= 0 )
                    len = min( len, (int)v[pos].size() - dp_overlap[pos][i] + solve(i, mask|(1<<i)));
                else
                    len = min( len, solve(i, mask|(1<<i)));
            }
        }
        if( pos >= 0)
            return dp[pos][mask] = len;
        else 
            return len;
    }
    
    string print(int pos, int mask, int mini, string s){
        if( bitcount(mask) == v.size() ){
            return s;
        }
        
        for( int i = 0 ; i < v.size(); ++i ){
            if( !(mask & (1<<i)) ){
                if( pos >= 0 ){
                    int ov = dp_overlap[pos][i];
                    int cnt = (int)v[pos].size() - ov;
                    if( cnt + dp[i][ mask|(1<<i)] == mini )
                        return print(i, mask|(1<<i), mini - cnt, s + v[i].substr(ov) );
                }else if( dp[i][mask|(1<<i)] == mini ){
                    return print(i, mask|(1<<i), mini, s + v[i]);
                }
            }
        }
        return s;
    }
    
    
    string shortestSuperstring(vector<string> &A) {
        v = A;
        precal();
        memset(dp, -1, sizeof(dp));
        int mini = solve(-1,0);
        string s = "";
        return print(-1, 0, mini, s);
    }
};
