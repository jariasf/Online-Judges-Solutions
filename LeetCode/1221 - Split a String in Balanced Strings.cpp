/*******************************************
 ***Problema: Split a String in Balanced Strings
 ***ID: 1221
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int total = 0;
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == 'L' ){
                cnt++;
            }else{
                cnt--;
            }
            total += (cnt == 0);
        }
        return total;
    }
};
