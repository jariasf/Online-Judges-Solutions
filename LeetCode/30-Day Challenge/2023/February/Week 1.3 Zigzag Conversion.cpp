/*******************************************
 ***Problema: Zigzag Conversion
 ***ID: Week 1.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1 ) return s;
        int n = s.size(), incr = numRows + (numRows - 2);
        string res = "";
        for(int i = 0 ; i < numRows; ++i){
            int j = i;
            while( j < n ){
                res += s[j];
                if( i > 0 && i < numRows - 1){
                    int k = j + incr - 2 * i; 
                    if( k < n )
                        res += s[k];
                }
                j += incr;
            }
        }
        return res;
    }
};
