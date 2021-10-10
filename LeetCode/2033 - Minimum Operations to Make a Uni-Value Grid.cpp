/*******************************************
 ***Problema: Minimum Operations to Make a Uni-Value Grid
 ***ID: 2033
 ***Juez: LeetCode
 ***Tipo: Sorting + Median
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int h = grid.size(), w = grid[0].size(), n = h * w;
        
        vector<int> v;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                v.push_back(grid[i][j]);
                if( grid[i][j] % x != grid[0][0] % x ) return -1;
            }
        }

        sort(v.begin(), v.end());
        int m1 = v[n/2];
        int res = 0;
        for( int val: v){
            res += abs(val - m1)/x;
        }
        
        if( n % 2 == 0 ){
            int m2 = v[n/2 -1];
            int tmp = 0;
            for( int val: v){
                tmp += abs(val - m2)/x;
            }
            res = min(res, tmp);
        }
        return res;
    }
};
