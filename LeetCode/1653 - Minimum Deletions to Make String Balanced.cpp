/*******************************************
 ***Problema: Minimum Deletions to Make String Balanced
 ***ID: 1653
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> sum(n + 2);
        for( int i = 1 ; i <= n ; ++i ){
            if( s[i - 1] == 'b') sum[i] = sum[i - 1] + 1;
            else sum[i] = sum[i - 1];
        }
        int res = INT_MAX;
        for( int i = 1 ; i <= n + 1; ++i ){
            int lb = sum[n] - sum[i - 1];
            int fb = sum[i - 1];
            res = min(res, n - i + 1 - lb + fb  );
        }
        return res;
    }
};
