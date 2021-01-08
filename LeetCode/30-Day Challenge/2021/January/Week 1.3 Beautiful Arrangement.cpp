/*******************************************
 ***Problema: Beautiful Arrangement
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int solve(int n, vector<int>& v){
        if( n == 0 ) return 1;
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( v[i] % n == 0 || n % v[i] == 0 ){
                swap(v[i], v[n-1]);
                res += solve( n - 1 , v );
                swap(v[i], v[n-1]);
            }
        }
        return res;
    }    
    
    int countArrangement(int n) {
        vector<int> v(n);
        for( int i = 0 ; i < n ; ++i ) v[i] = i + 1;
        return solve(n, v);
    }
};
