/*******************************************
 ***Problema: Jump Game
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canJump(vector<int>& A) {
        int sz = A.size();
        if(sz == 1) return 1;
        vector<int> zeros;
        int largest = 0, index = 0;
        for( int i = 0 ; i < sz - 1 ; ++i ){
            if( A[i] == 0 ){
                if( largest <= i ){
                    return 0;
                }
            }else{
                if( largest < (i + A[i]) ){
                    largest = i + A[i];
                    index = i;
                }
            }
        }
        return 1;
    }
};
