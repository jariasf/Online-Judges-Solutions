/*******************************************
 ***Problema: Consecutive Characters
 ***ID: 1446
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maxi = 1, cnt = 1;
        for( int i = 1 ; i < n ; ++i ){
            if( s[i] == s[i - 1]) 
                cnt++;
            else
                cnt = 1;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
