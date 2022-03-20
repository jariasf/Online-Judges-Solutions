/*******************************************
 ***Problema: Minimum White Tiles After Covering With Carpets
 ***ID: 2208
 ***Juez: LeetCode
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 1005
int dp[MAX][MAX];
class Solution {
public:
    #define INF 1<<30
    string s;
    int solve(int pos, int cnt, int len){
        if( pos >= s.size() ) return 0;
        if( dp[pos][cnt] != -1 ) return dp[pos][cnt];
        int res = (s[pos] == '1') + solve(pos + 1, cnt, len);
        if( cnt > 0 ){
            res = min(res, solve(pos + len, cnt - 1, len));
        }
        return dp[pos][cnt] = res;
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        s = floor;
        memset(dp, -1, sizeof(dp));
        return solve(0, numCarpets, carpetLen);
    }
};
