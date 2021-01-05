/*******************************************
 ***Problema: Game of Life
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define LIVE 2
    #define DEAD 3
    void gameOfLife(vector<vector<int>> &board) {
        int h = board.size(), w = board[0].size();
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                int live = 0;
                for( int ii = -1; ii <= 1 ; ++ii ){
                    for( int jj = -1; jj <= 1 ; ++jj ){
                        if( ii == 0 && jj == 0 ) continue;
                        int nx = i + ii, ny = j + jj;
                        if( nx >= 0 && nx < h && ny >= 0 && ny < w && 
                           (board[nx][ny] == 1 || board[nx][ny] == DEAD) ){
                            live++;
                        }
                    }
                }
                if( board[i][j] == 1 ){
                    if( live < 2 || live > 3 ){
                        board[i][j] = DEAD;
                    }
                }else if(live == 3){
                    board[i][j] = LIVE;
                }
            }
        }
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( board[i][j] == DEAD ) board[i][j] = 0;
                else if( board[i][j] == LIVE) board[i][j] = 1;
            }
        }
    }
};
