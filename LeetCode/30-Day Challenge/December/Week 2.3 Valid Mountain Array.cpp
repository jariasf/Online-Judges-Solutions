/*******************************************
 ***Problema: Valid Mountain Array
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if( n < 3 ) return false;
        
        int ini = A[0];
        if( A[0] > A[1]){
            return false;
        }else if( A[0] == A[1]){
            return false;
        }else{
            int i = 1;
            while( i < n && A[i] > A[i - 1] ){
                i++;
            }
            if( i == n ) return false;
            if( A[i] == A[i - 1]) return false;
            while( i < n && A[i] < A[i - 1] ){
                i++;
            }
            
            if( i == n ) return true;
        }
        
        return false;
    }
};
