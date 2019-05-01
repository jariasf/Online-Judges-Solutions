/****************************************************
 ***Problema: Minimum Domino Rotations For Equal Row
 ***ID: 1007
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int mini = 1<<30;
        for( int k = 1 ; k <= 6 ; ++k ){
            int up = 0, down = 0;
            for( int i = 0 ; i < n ; ++i ){
                if( A[i] == k ) continue;
                if( B[i] == k ) up++;
                else{
                    up = 1<<30;
                    break;
                }
            }
            
            for( int i = 0 ; i < n ; ++i ){
                if( B[i] == k ) continue;
                if( A[i] == k ) down++;
                else{
                    down = 1<<30;
                    break;
                }
            }
            mini = min( mini, min(up, down));
        }
        if( mini == 1<<30 ) return -1;
        return mini;
    }
};
