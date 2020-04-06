/*******************************************
 ***Problem: Longest Happy String
 ***ID: 1405
 ***Judge: LeetCode
 ***Type: Greedy
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string solve(int l, int m , int s, char c_l = 'a', char c_m = 'b', char c_s = 'c'){
        //set order l > m > s
        if( l < m )
            return solve(m, l, s, c_m, c_l, c_s);
        if( m < s )
            return solve(l, s, m, c_l, c_s, c_m);
        
        //work with first two largest
        if( m == 0 )
            return string( min(2, l), c_l);
        
        int num_l = min(2, l), num_m = 0;
        
        //if l is still large, add 1 m
        if( l - num_l >= m ) num_m = 1;
        
        return string(num_l, c_l) + string(num_m, c_m) + 
               solve(l - num_l, m - num_m, s, c_l, c_m, c_s);
    }

    
    string longestDiverseString(int a, int b, int c) {
        return solve(a, b, c);
    }
};
