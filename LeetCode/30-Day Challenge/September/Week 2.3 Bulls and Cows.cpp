/*******************************************
 ***Problema: Bulls and Cows
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), A = 0, B = 0;
        vector<int> cnt(10);
        for( int i = 0 ; i < n ; ++i ){
            if( secret[i] == guess[i] ){
                A++;         
            }else{
                if( cnt[secret[i] - '0']++ < 0 )
                    B++;                
                if( cnt[guess[i] - '0']-- > 0 )
                    B++;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
