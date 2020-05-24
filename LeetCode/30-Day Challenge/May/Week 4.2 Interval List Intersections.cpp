/*******************************************
 ***Problema: Interval List Intersections
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:   
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), m = B.size();
        int i = 0 , j = 0;
        vector<vector<int> > res;
        while( i < n && j < m ){
            int left = max(A[i][0], B[j][0]);
            int right = min(A[i][1], B[j][1]);
            if( left <= right ) res.push_back({left, right});
            if( A[i][1] < B[j][1]) i++;
            else j++;
        }
        return res;
    }
};
