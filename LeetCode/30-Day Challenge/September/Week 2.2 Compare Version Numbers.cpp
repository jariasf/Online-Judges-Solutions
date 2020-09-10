/*******************************************
 ***Problema: Compare Version Numbers
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0, v1, v2;
        while( i < s1.size() || j < s2.size() ){
            v1 = v2 = 0;
            while( i < s1.size() && s1[i] != '.' )
                v1 = v1 * 10 + s1[i++] - '0';
            while( j < s2.size() && s2[j] != '.')
                v2 = v2 * 10 + s2[j++] - '0';
            if( v1 > v2 ) return 1;
            else if( v1 < v2 ) return -1;
            i++; j++;
        }
        return 0;
    }
};
