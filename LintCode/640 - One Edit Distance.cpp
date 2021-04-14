/*******************************************
 ***Problema: One Edit Distance
 ***ID: 640
 ***Juez: LintCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        int n = s.size(), m = t.size();
        if( abs(n - m) > 1 ) return false;
        int i = 0, j = 0, diff = 0;
        while(i < n && j < m){
            if( s[i] != t[j] ){
                if( diff == 1 ) return false;
                if( n < m ){
                    j++;
                }else if( n > m ){
                    i++;
                }
                diff++;
            }
            i++; j++;
        }

        if(i < n || j < m) diff++;
        return diff == 1;
    }
};
