/*******************************************
 ***Problema: Minimum Cost to Cut a Stick
 ***ID: 1567
 ***Juez: LeetCode
 ***Tipo: Prefix Product
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int n = A.size();        
        for( int i = 0 ; i < n ; ++i ){
            if( A[i] > 0 ) A[i] = 1;
            else if( A[i] < 0 ) A[i] = -1;
        }
        
        int neg = -1, maxi = 0, pos = -1;
        for( int i = 0 ; i < n ; ++i ){
            if( i > 0 )
                A[i] *= A[i - 1];
            
            if( A[i] < 0 ){
                if( neg == -1 ) neg = i;
                else{
                    maxi = max(i - neg, maxi);
                }
            }else if( A[i] == 0 ){
                neg = -1;
                pos = i;
                A[i] = 1;
            }else{
                maxi = max(i - pos, maxi);
            }
        }
        return maxi;
    }
};
