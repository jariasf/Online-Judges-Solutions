/*******************************************
 ***Problema: Word Search
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<char> > grid;
    bool dfs(string &word, int pos, int x , int y){
        if( pos == word.size() ) return true;
        char tmp = grid[x][y];
        grid[x][y] = '.';
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if( nx >= 0 && ny >= 0 && nx < grid.size() 
                && ny < grid[0].size() && grid[nx][ny] == word[pos]
                && dfs(word, pos + 1, nx, ny))
                return true;
        }
        grid[x][y] = tmp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        grid = board;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == word[0] && dfs(word, 1, i, j) ) 
                    return true;
            }
        }
        return false;
    }
};
