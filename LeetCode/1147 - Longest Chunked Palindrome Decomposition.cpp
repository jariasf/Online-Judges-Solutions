/*******************************************
 ***Problema: Longest Chunked Palindrome Decomposition
 ***ID: 1147
 ***Juez: LeetCode
 ***Tipo: Hashing, Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define MAX 1005
    #define BASE 43
    #define C 5381
    typedef unsigned long long LLU;
    const long long MOD = 1000000007;
    LLU pot[ MAX ];
    LLU hash[ MAX ];
    
    void initPot(){
        pot[ 0 ] = 1;
        for( int i = 1 ; i < MAX ; ++i ) pot[ i ] = pot[ i - 1 ] * BASE;
    }

    int V( char c ){
        return c - 'a' + 1;
    }

    void initHash(string &text){
        int len = text.size();
        hash[ 0 ] = C;
        for( int i = 1 ; i <= len ; ++i ) hash[ i ] = hash[ i - 1 ] * BASE + V( text[ i - 1 ] ) ;
    }

    LLU calc_hash( int a , int b ){
        return hash[ b ] - hash[ a ] * pot[ b - a ];
    }

    int dp[MAX][MAX];
    string s;
    int solve(int left, int right){
        if( left >= right ) return 0;
        if(dp[left][right]  != -1 ) return dp[left][right];
        int result = 0;
        int n = s.size();  
        for( int i = left + 1; i <= n; ++i ){
            if( (i <= right - i + left) && calc_hash(left, i) == calc_hash(right - (i - left), right) ){
                result = max(result, 2 + solve( i, right - i + left));
            }else{
                result = max(result, 1);
            }
        }
        return dp[left][right] = result;        
    }
    
    int longestDecomposition(string text) {
        int result = 1;
        int n = text.size();
        s = text;
        initPot();
        initHash(text);
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};
