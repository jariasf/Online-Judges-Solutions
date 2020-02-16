/*******************************************
 ***Problem: Count Negative Numbers in a Sorted Matrix
 ***ID: 1351
 ***Judge: LeetCode
 ***Type: Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int cnt = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] < 0 ) cnt++;
            }
        }
        return cnt;
    }
};
