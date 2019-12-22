/*******************************************
 ***Problema: Find Winner on a Tic Tac Toe Game
 ***ID: 1275
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define X 1
    #define O 2
    
    bool winner(vector<vector<int> > &grid){
        bool row, col ,diag;
        row = col = diag = true;
        for( int i = 0 ; i < 3 ; ++i ){
            row = true;
            for( int j = 0 ; j < 3 ; ++j ){
                if( grid[i][j] == 0 ){
                    row = false;
                    break;
                }
                if(j > 0 && grid[i][j] != grid[i][j - 1]){
                    row = false;
                    break;
                }
            }
            if( row ) return true;
        }
        
        
        for( int i = 0 ; i < 3 ; ++i ){
            col = true;
            for( int j = 0 ; j < 3 ; ++j ){
                if( grid[j][i] == 0 ){
                    col = false;
                    break;
                }
                if(j > 0 && grid[j][i] != grid[j - 1][i]){
                    col = false;
                    break;
                }
            }
            if( col ) return true;
        }
        
        diag = true;
        for( int i = 1; i < 3 ; ++i ){
            if( grid[i][i] == 0 || grid[i][i] != grid[i - 1][i - 1]){
                diag = false;            
                break;
            }
        }
        if( diag ) return true;
        
        if( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0 ) return true;

        return false;
    }
    
    bool full(vector<vector<int> > &grid){
        for( int i = 0 ; i < 3 ; ++i ){
            for( int j = 0 ; j < 3 ; ++j ){
                if( grid[i][j] == 0 ) return false;
            }
        }
        return true;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int> > grid(3, vector<int>(3));
        for( int i = 0 ; i < n ; ++i ){
            int x = moves[i][0], y = moves[i][1];
            grid[x][y] = (i % 2 == 0?X:O);
            if( winner(grid) ){
                if( i & 1 ){
                    return "B";
                }else
                    return "A";
            }
        }
        
        if( full(grid) ) return "Draw";        
        return "Pending";
    }
};
