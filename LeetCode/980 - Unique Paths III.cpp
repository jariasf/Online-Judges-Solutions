/*******************************************
 ***Problema: Unique Paths III
 ***ID: 980
 ***Juez: LeetCode
 ***Tipo: DFS, Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int getId(int x, int y, int w){
        return x * w + y;
    }
    
    int bitcount( int n ){
        int cnt = 0;
        while( n ){
            n = n & ( n - 1 );
            cnt++;
        }
        return cnt;
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int num_zeros;
    int traverse(vector<vector<int>>& grid, int mask, int x, int y, int zeros){
        int h = grid.size(), w = grid[0].size();
        
        if( grid[x][y] == 2 ){
            if( zeros == num_zeros ){
                return 1;
            }
            return 0;
        }
        
        int result = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != -1 ){
                int id = getId(nx, ny, w);
                if(!(mask & (1<<id))){
                    result += traverse(grid, mask | (1<<id), nx, ny, zeros + (grid[nx][ny] == 0) );
                }
            }
        }
        return result;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        num_zeros = 0;
        int x, y;
        int h = grid.size(), w = grid[0].size();
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 0 )
                    num_zeros++;
                if( grid[i][j] == 1 ){
                    x = i; y = j;
                }
            }
        }
        return traverse(grid, 1<<getId(x,y,w), x , y, 0);
        
    }
};
