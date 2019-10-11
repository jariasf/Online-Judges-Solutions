/*******************************************
 ***Problema: Smallest Good Base
 ***ID: 1213
 ***Juez: LintCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef unsigned long long LL; 
    #define LARGER 3    
    #define SMALLER 1
    #define SAME 2
    int toBase(int len, LL base, LL n ){
        LL sum = 1, p = 1;
        for( int i = 2 ; i <= len ; ++i ){
            if( p >= ULLONG_MAX/base ) return LARGER;
            p *= base;
            if(sum > n - p || sum >= ULLONG_MAX - p) return LARGER;
            sum += p;
        }
        if( sum == n ) return SAME;
        if( sum > n ) return LARGER;
        return SMALLER;
    }
    
    string smallestGoodBase(string &s) {
        int len = 100;
        LL n = stoull(s);
        LL minimum = ULLONG_MAX;
        for( int i = 1; i <= len ; ++i ){
            LL left = 2, right = ULLONG_MAX, result = -1;
            while( left < right ){
                LL mid = left + (right - left)/2;
                int comp = toBase(i, mid, n);
                if( comp == SAME ){
                    result = mid;
                }
                if( comp == SAME || comp == LARGER ){
                    right = mid;
                }else
                    left = mid + 1;
            }
            if( result != -1 ){
                minimum = min( minimum, result);
            }
        }
        return to_string(minimum);
    }
};
