/*******************************************
 ***Problema: Prime Arrangements
 ***ID: 1175
 ***Juez: LeetCode
 ***Tipo: Prime Numbers + Combinatorics
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    #define MOD 1000000007    
    bool isPrime(int n){
        int i;
        if( n == 2 )
            return 1;

        if( n % 2 == 0)
            return 0;

        for( i = 3 ; i * i <= n; i += 2 )
            if( n % i == 0 )
                return 0;
        return 1;
    }

    int numPrimeArrangements(int n) {
        int p = 0;
        vector<LL> fact(n + 5);
        fact[0] = fact[1] = 1;
        for( int i = 2 ; i <= n ; ++i ){
            if( isPrime(i) ) p++;
            fact[i] = i * fact[i - 1] % MOD;
            fact[i] %= MOD;
        }
        int o = n - p;
        return (fact[p] * fact[o]) % MOD;
    }
};
