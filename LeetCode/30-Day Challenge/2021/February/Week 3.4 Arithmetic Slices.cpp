/*******************************************
 ***Problema: Arithmetic Slices
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        for( int i = 0 ; i + 1< n ; ++i ){
            int j = i + 1, cnt = 1;
            int dif = A[j] - A[j - 1];
            while( j < n && A[j] - A[j - 1] == dif ){
                j++;
                cnt++;
            }
            i = j - 1;
            if( cnt > 1 )
                i--;
            
            if( cnt - 2 > 0 ){
                cnt -= 2;
                ans += cnt * ( cnt + 1)/2;
            }
        }
        return ans;
    }
};
