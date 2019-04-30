/*******************************************
 ***Problema: Numbers With Repeated Digits
 ***ID: 1012
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define MAX 10
    int digit[ MAX ] , sz;
    void getDigits( long long n ){
        sz = 0;
        int digitInv[ MAX ] , i , j;
        while( n > 0 ){
            digitInv[ sz++ ] = n % 10;
            n /= 10;
        }

        for( i = sz - 1 , j = 0 ; i >= 0 ; --i , ++j ){
            digit[ j ] = digitInv[ i ];
        }
    }

    long long dp[ MAX ][ 2 ][ 1<<MAX ][2][2];
    long long solve( int len,  int flag, int mask, bool correct, bool first_zero ){
        if( len == sz ){
            if( correct == 1 ) return 1;
            return 0;
        }
        
        if(dp[len][flag][mask][correct][first_zero] != -1 ) return dp[len][flag][mask][correct][first_zero];
        int maxDigit = digit[ len ] , i , aux;
        if( flag ) maxDigit = 9;
        long long ans = 0;
        for( i = 0 ; i <= maxDigit ; ++i ){
            if( i == 0 && first_zero ){
                ans += solve( len + 1, flag | ( ( i < digit[ len ] )?1:0 ), mask, correct, true );
            }else{
                if( mask & (1<<i)){
                    ans += solve( len + 1, flag | ( ( i < digit[ len ] )?1:0 ), mask | (1<<i), true, false );
                }else{
                    ans += solve( len + 1, flag | ( ( i < digit[ len ] )?1:0 ), mask | (1<<i), correct, false );
                }
            }
        }
        return dp[len][flag][mask][correct][first_zero] = ans;
    }
    
    int numDupDigitsAtMostN(int N) {
        getDigits(N);
        memset(dp, -1, sizeof(dp));
        return solve(0, false, 0, false, true);
    }
};
