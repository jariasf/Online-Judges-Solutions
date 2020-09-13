/*******************************************
 ***Problema: Maximum Product Subarray
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxProduct(vector<int>& A) {
        int sz = A.size();
        vector<int> maxi(A.begin(),A.end()), mini(A.begin(), A.end());
        int ans = A[0];
        for( int i = 1 ; i < sz ; ++i ){
            int p1 = maxi[i - 1] * A[i], p2 = mini[ i - 1 ] * A[i];
            maxi[i] = max( A[i] , max(p1, p2) );
            mini[i] = min( A[i] , min(p1, p2) );
            ans = max( ans, maxi[i]);
            ans = max( ans, mini[i]);
        }
        return ans;
    }
};
