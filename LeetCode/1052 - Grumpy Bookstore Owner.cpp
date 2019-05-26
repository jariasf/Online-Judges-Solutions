/*******************************************
 ***Problema: Grumpy Bookstore Owner
 ***ID: 1052
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
        int n = c.size();
        vector<int> sums(n + 1);
        vector<int> s(n + 1);
        for( int i = 1 ; i <= n ; ++i ){
            sums[i] = sums[i - 1] + c[i - 1];
            if( g[i - 1] == 0 ){
                s[i] = s[i - 1] + c[i - 1];
            }else
                s[i] = s[i - 1];
        }
        
        int result = 0;
        for( int i = 1 ; i <= n - X + 1 ; ++i ){
            result = max( result, s[i - 1] + s[n] - s[i + X - 1] + sums[ i + X - 1] - sums[ i - 1 ] ); 
        }
        
        return result;
    }
};
