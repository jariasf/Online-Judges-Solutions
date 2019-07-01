/*******************************************
 ***Problema: Sort Array By Parity II
 ***ID: 922
 ***Juez: LeetCode
 ***Tipo: Ad hoc, two passes
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd, even;
        int n = A.size();
        for( int i = 0 ; i < n ; ++i ){
            if( A[i] & 1 ){
                odd.push_back(A[i]);
            }else
                even.push_back(A[i]);
        }
        
        vector<int> res(n);
        for( int i = 0, o = 0, e = 0 ; i < n ; ++i ){
            if( i % 2 == 0 ){
                res[i] = even[e++];
            }else{
                res[i] = odd[o++];
            }
        }
        return res;
        
        
    }
};
