/*******************************************
 ***Problema: Sum of Scores of Built Strings
 ***ID: 2223
 ***Juez: LeetCode
 ***Tipo: Z Algorithm
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;

    vector<int> Z(string &s) {
        int L = 0, R = 0 , n = s.size() , i , k;
        vector<int> z(n);
        for( i = 1 ; i < n ; ++i ) {
            if( i > R ) {
                L = R = i;
                while( R < n && s[ R - L ] == s[ R ] ) R++;
                z[ i ] = R - L; R--;
            } else {
                k = i - L;
                if( z[ k ] < R - i + 1 ) z[ i ] = z[ k ];
                else {
                    L = i;
                    while( R < n && s[ R - L ] == s[ R ] ) R++;
                    z[ i ] = R - L; R--;
                }
            }
        }
        return z;
    }    
    
    long long sumScores(string s) {
        vector<int> b = Z(s);
        LL res = s.size();
        for( int i = 0 ; i < b.size(); ++i ){
            res += b[i];
        }
        return res;
    }
};
