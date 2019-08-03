/*******************************************
 ***Problema: Narcissistic Number
 ***ID: 147
 ***Juez: LintCode
 ***Tipo: Ad hoc, Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: The number of digits
     * @return: All narcissistic numbers with n digits
     */
     
    vector<int> pot;
    bool isNar(int x, int len){
        if( x == 0 ) return true;
        int sum = 0, _x = x;
        _x = x;
        while(_x > 0 ){
            int d = _x % 10;
            sum += pot[d];
            if( sum > x ) return false;
            _x /= 10;
        }
        return sum == x;
    }
    
    vector<int> getNarcissisticNumbers(int n) {
        //precalculate powers
        pot = vector<int>(10, 1);
        for( int i = 0 ; i < 10 ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                pot[i] = pot[i] * i;
            }
        }
        
        //define range
        int low = 1;
        for( int i = 1; i < n ;++i ){
            low = low * 10;
        }
        int up = low * 10;
        if( n == 1 ) low = 0;

        //simulate
        vector<int> res;
        for( int i = low ; i <= up; ++i ){
            if( isNar(i, n) )
                res.push_back(i);
        }     
        
        return res;        
    }
};
