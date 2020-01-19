/*******************************************
 ***Problema: Minimum Number of Taps to Open to Water a Garden
 ***ID: 1326
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30
    vector<int> v;
    int N;
    vector<int> dp;
    int solve(int pos){
        if( pos >= N )
            return 0;

        if( dp[pos] != -1 ) 
            return dp[pos];
        int res = INF;
        for( int i = pos; i < v.size(); ++i ){
            if(  i - v[i] <= pos && pos <= i + v[i] ){
                if( i + v[i] != pos ){
                    res = min(res, 1 + solve(min(i + v[i],N)));
                }
            }
        }
        return dp[pos] = res;
    }
    
    int minTaps(int n, vector<int>& ranges) {
        v = ranges;
        N = n;
        dp = vector<int>(n + 5, -1);
        int res= solve(0);
        if( res >= INF ) return -1;
        return res;
    }
};
