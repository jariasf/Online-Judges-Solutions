/*******************************************
 ***Problema: Simplified Fractions
 ***ID: 1447
 ***Juez: LeetCode
 ***Tipo: GCD
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int gcd(int a , int b){
       return  ( b == 0 ) ? a:gcd( b , a % b );
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for( int i = 2 ; i <= n ; ++i ){
            for( int j = 1 ; j < i ; ++j ){
                if( gcd(i, j) == 1 ){
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }
};
