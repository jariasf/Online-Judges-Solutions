/*******************************************
 ***Problema: Complement of Base 10 Integer
 ***ID: 1009
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int bitwiseComplement(int N) {
        if( N == 0 ) return 1;
        long long val = 0;
        bool start = false;
        for( int i = 31 ; i >= 0 ; --i ){
            if( N & (1<<i) ){
                start = true;
            }else if( start ){
                val |= 1<<i;
            }
        }
        return val;
    }
};
