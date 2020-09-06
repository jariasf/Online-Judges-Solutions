/*******************************************
 ***Problema: Replace All ?'s to Avoid Consecutive Repeating Characters
 ***ID: 1576
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '?'){
                int a = -1, b = -1;
                if( i - 1 >= 0 ) a = s[i - 1] - 'a';
                if( i + 1 < n ) b = s[i + 1] - 'a';
                for( int j = 0 ; j < 26 ; ++j ){
                    if( j != a && j != b ){
                        s[i] = (char)(j + 'a');
                        break;
                    }
                }
            }
        }
        return s;
    }
};
