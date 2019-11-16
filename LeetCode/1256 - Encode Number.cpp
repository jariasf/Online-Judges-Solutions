/*******************************************
 ***Problema: Encode Number
 ***ID: 1256
 ***Juez: LeetCode
 ***Tipo: Binary Numbers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    string encode(int num) {
        if( num == 0 ) return "";
        LL sum = 0;
        LL val = 0;
        int bits = 0;
        for( int i = 1 ; i < 33 ; ++i ){
            if( sum + (1LL<<i) >= num ){
                val = num - sum;
                bits = i - 1;
                break;
            }
            sum += (1LL<<i);   
        }
        val--;
        string res = "";
        for( int i = bits ; i >= 0 ; --i ){
            if( val & (1<<i) ){
                res += "1";
            }else
                res += "0";
        }
        return res;
    }
};
