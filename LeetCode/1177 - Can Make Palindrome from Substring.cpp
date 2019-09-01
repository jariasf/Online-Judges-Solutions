/*******************************************
 ***Problema: Can Make Palindrome from Substring
 ***ID: 1177
 ***Juez: LeetCode
 ***Tipo: Prefix Sums + Palindrome
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> result(queries.size(), false);
        vector< vector<int> > hash(n + 5, vector<int>(27) );
        for( int i = 1 ; i <= n ; ++i ){
            hash[ i ][ s[i - 1] - 'a' ] = hash[ i - 1 ][ s[i - 1] - 'a' ] + 1;
            for( int j = 0 ; j < 26 ; ++j ){
                if( j != s[i - 1] - 'a' ){
                    hash[i][j] = hash[i - 1][j];
                }
            }
        }
        
        for( int i = 0 ; i < queries.size() ; ++i ){
            int k = queries[i][2];
            int left = queries[i][0] + 1;
            int right = queries[i][1] + 1;
            int len = right - left + 1;
            int cnt_odd = 0;
            for( int j = 0 ; j < 26 ; ++j ){
                int cnt = hash[right][j] - hash[left - 1][j];
                if( cnt & 1){
                    cnt_odd++;
                }
            }
            if( len & 1 ) cnt_odd--;
            k -= cnt_odd/2;
            if(k >= 0) result[i] = true;
        }
        return result;
    }
};
