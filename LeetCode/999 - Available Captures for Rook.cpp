/*******************************************
 ***Problema: Available Captures for Rook
 ***ID: 999
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int dx[4] = {0,  0, -1, 1};
    int dy[4] = {1, -1,  0, 0};
    
    int numRookCaptures(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        int x, y;
        x = y = 0;
        for( int i = 0 ; i<  h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){                
                if( board[i][j] == 'R'){
                    x = i; y = j;
                }
            }
        }
        
        int result = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            int k = 1;
            while(true){
                int nx = k * dx[i] + x;
                int ny = k * dy[i] + y;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                    if( board[nx][ny] == 'B' ) break;
                    if( board[nx][ny] == 'p' ){
                        result++;
                        break;
                    }
                }else
                    break;
                k++;
            }
        }
        return result;
    }
};
