/*******************************************
 ***Problema: Reverse Only Letters
 ***ID: 917
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        string aux = "";
        for( int i = 0 ; i < n ; ++i ){
            if( isalpha(S[i]) ){
                aux += S[i];
            }
        }
        reverse(aux.begin(), aux.end());
        
        string res = "";
        for( int i = 0 , j = 0; i< n ; ++i ){
            if( isalpha(S[i]) ){
                res += aux[j++];
            }else
                res += S[i];
        }
        return res;
    }
};
