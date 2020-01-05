/*******************************************
 ***Problema: Decrypt String from Alphabet to Integer Mapping
 ***ID: 1308
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    string freqAlphabets(string s) {
        int n = s.size();
        string res = "";
        for( int i = 0 ; i < n ; ++i ){
            if( i + 1 < n && isdigit(s[i + 1]) && i + 2 < n && !isdigit(s[i + 2])){
                res += (char)( (s[i] - '0')* 10 + (s[i + 1] - '0') - 1 + 'a' );
                i += 2;
            }else{
                res += (char)(s[i] - '0' - 1 + 'a');
            }          
        }
        return res;
    }
};
