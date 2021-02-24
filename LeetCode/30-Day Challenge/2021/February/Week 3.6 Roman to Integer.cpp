/*******************************************
 ***Problema: Roman to Integer
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int romanToInt(string s) {
        int val[ 256 ] = { -1 };
        if ( val[ 0 ] < 0) {
            int a[] = { 1 , 5 , 10 , 50 , 100 , 500 , 1000 };
            for (int i = 0; i < 256; ++i ) val[ i ] = 0;
            for (int i = 0; i < 7; ++i ) val[ "IVXLCDM"[ i ] ] = a[ i ];
        }

        int res = 0;
        for ( int i = 0 ; i < s.size() ; ++i ) {
            res += val[ s[i] ];
            for ( int j = i + 1 ; j < s.size() ; ++j ) {
                if ( val[ s[j] ] > val[ s[i] ] ) {
                    res -= 2 * val[ s[i] ];
                    break;
                }
            }
        }
        return res;
    }
};
