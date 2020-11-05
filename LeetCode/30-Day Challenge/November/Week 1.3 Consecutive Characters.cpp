/*******************************************
 ***Problema: Consecutive Characters
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxPower(string s) {
        char last = s[0];
        int cnt = 0, maxi = 0;
        for(char c:s ){
            if( c == last ){
                cnt++;
            }else{
                maxi = max(maxi, cnt);
                cnt = 1;
            }
            last = c;
        }
        maxi = max(maxi, cnt);
        return maxi;
    }
};
