/*******************************************
 ***Problema: Image Overlap
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


// Brute Force O(n^4)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), maxi = 0;
        for( int i = 1 - n ; i < n ; ++i ){
            for( int j = 1 - n ; j < n ; ++j ){
                int cnt = 0;
                for( int ii = i, x = 0 ; x < n ; ++x ){
                    for( int jj = j, y = 0 ; y < n ; ++y ){
                        int a = 0, b = B[x][y];
                        if( i + x >= 0 && i + x < n && j + y >= 0 && j + y < n )
                            a = A[i + x][j + y];
                        cnt += (a && b);
                    }
                }
                maxi = max( maxi, cnt);
            }
        }
        return maxi;
    }
};
