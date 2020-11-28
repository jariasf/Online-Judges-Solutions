/*******************************************
 ***Problema: Maximum Repeating Substring
 ***ID: 1668
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxRepeating(string seq, string w){
        int res = 0, n = w.size(), j;
        for( int i = 0 ; i < seq.size(); ++i ){
            for( j = 0 ; i + j < seq.size(); ++j ){
                if( seq[i + j] != w[j % n] ) break;
            }
            res = max(res, j/n);
        }
        return  res;
    }
};
