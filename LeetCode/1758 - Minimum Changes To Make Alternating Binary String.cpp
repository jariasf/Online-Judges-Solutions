/*******************************************
 ***Problema: Minimum Changes To Make Alternating Binary String
 ***ID: 1758
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minOperations(string s) {
        int a = 0 , b = 0;
        for( int i = 0 ; i < s.size(); ++i ){
            if( i & 1 ){
                if( s[i] == '1') a++;
                else b++;
            }else{
                if( s[i] == '0') a++;
                else b++;
            }
        }
        return min(a,b);
    }
};
