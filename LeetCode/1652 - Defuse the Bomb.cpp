/*******************************************
 ***Problema: Defuse the Bomb
 ***ID: 1652
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);
        for( int i = 0 ; i < n ; ++i ){
            if( k > 0 ){
                for( int j = i + 1; j < i + k + 1 ; ++j )
                    res[i] += code[j%n];
            }else{
                for( int j = i - 1; j > i + k - 1 ; --j )
                    res[i] += code[(j + n)%n];                
            }
        }
        return res;
    }
};
