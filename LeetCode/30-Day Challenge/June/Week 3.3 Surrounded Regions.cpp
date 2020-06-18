/*******************************************
 ***Problema: Surrounded Regions
 ***ID: Week3.3
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        
        int h = board.size();
        if( h == 0 ) return;
        int w = board[0].size();
        queue<pii> Q;
        for( int i = 0 ; i < h ; ++i ){
            if( board[i][0] == 'O'){
                Q.push( mp(i, 0) );
                board[i][0] = '1';
            }
            if(board[i][w - 1] == 'O'){
                Q.push( mp(i, w - 1) );
                board[i][w - 1] = '1';
            }
        }
        
        for( int i = 0 ; i < w ; ++i ){
            if( board[0][i] == 'O'){
                Q.push( mp(0, i) );
                board[0][i] = '1';
            }
            if(board[h - 1][i] == 'O'){
                Q.push( mp(h - 1, i) );
                board[h - 1][i] = '1';
            }
        }        
        
        while( !Q.empty() ){
            pii cur = Q.front(); Q.pop();
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = dir[i][0] + cur.first, ny = dir[i][1] + cur.second;
                if( nx >= 0 & ny >= 0 && nx < h && ny < w && board[nx][ny] == 'O' ){
                    board[nx][ny] = '1';
                    Q.push(mp(nx, ny));
                }
            }
        }
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( board[i][j] == 'O') board[i][j] = 'X';
                else if( board[i][j] == '1') board[i][j] = 'O';
            }
        }
        
    }
};
