/*******************************************
 ***Problema: Longest Duplicate Substring
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Binary Search the Answer + Rolling Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    

    #define BASE 43
    #define C 5381
    
    typedef unsigned long long LLU;
    const long long MOD = 1000000007;
    
    vector<LLU> pot, hash;

    void initPot(int n){
        pot[ 0 ] = 1;
        for( int i = 1 ; i < n ; ++i ) 
            pot[ i ] = pot[ i - 1 ] * BASE;
    }

    int V( char c ){
        return c - 'a' + 1;
    }

    void initHash(string &s){
        hash[ 0 ] = C;
        for( int i = 1 ; i <= s.size() ; ++i ) 
            hash[ i ] = hash[ i - 1 ] * BASE + V( s[ i - 1 ] ) ;
    }

    LLU calc_hash( int a , int b ){
        return hash[ b ] - hash[ a ] * pot[ b - a ];
    }
    
    string longestDupSubstring(string S) {
        int n = S.size();
        pot = vector<LLU>(n + 1, 0);
        hash = vector<LLU>(n + 2, 0);
        initPot(n);
        initHash(S);
        int left = 0, right = n;
        int max_len = 0, index = 0;
        while(left < right){
            int mid = (left + right)/2;
            unordered_map<LLU, int> cnt;
            bool found = false;
            for( int i = 0 ; i + mid <= n ; ++i ){
                LLU val = calc_hash(i, i + mid);
                cnt[ val ]++;
                if( cnt[val] > 1 ){
                    found =true;
                    index = i;
                    max_len = mid;
                    break;
                }
            }
            if( found ){
                left = mid + 1;
            }else{
                right = mid;
            }
            
        }
        if( max_len > 0 ) return S.substr(index, max_len);
        return "";
    }
};
