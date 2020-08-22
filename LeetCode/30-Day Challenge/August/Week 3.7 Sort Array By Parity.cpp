/*******************************************
 ***Problema: Sort Array By Parity
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        for( int i = 0, left = -1; i < n ; ++i ){
            if( A[i] & 1 ){
                if( left == -1){
                    left = i;
                }
            }else if( left != -1 ){
                swap(A[left++], A[i]);
            }
        }        
        return A;
    }
};
