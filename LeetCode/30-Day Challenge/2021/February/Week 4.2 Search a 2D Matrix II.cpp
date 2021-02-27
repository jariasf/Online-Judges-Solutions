/*******************************************
 ***Problema: Search a 2D Matrix II
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left, right, mid;
        int h = matrix.size(), w = matrix[0].size();
        int x = h - 1, y = 0;
        while( x >= 0 && y < w ){
            if( matrix[x][y] == target ) return true;
            if( matrix[x][y] < target ) y++;
            else x--;
        }
        return false;
    }
};
