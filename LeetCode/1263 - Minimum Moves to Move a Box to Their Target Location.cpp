/*******************************************
 ***Problema: Minimum Moves to Move a Box to Their Target Location
 ***ID: 1263
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct State{
        int x, y, xbox, ybox, d;
        State( int _x , int _y, int _xbox, int _ybox, int _d ){
            x = _x; y = _y; xbox = _xbox; ybox = _ybox; d = _d;
        }
        State(){}
    };
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    bool valid(int nx, int ny, int h, int w){
        return nx >= 0 && ny >= 0 && nx < h && ny < w;
    }

    int minPushBox(vector<vector<char>>& grid) {
        int h = grid.size(), w = grid[0].size();
        
        int xini, yini, xend, yend, xbox, ybox;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == 'S'){
                    xini = i; yini = j;
                }else if( grid[i][j] == 'T' ){
                    xend = i, yend = j;
                }else if( grid[i][j] == 'B'){
                    xbox = i, ybox = j;
                }
            }
        }
        
        queue<State> Q;
        Q.push( State(xini, yini, xbox, ybox, 0));
        int seen[h + 2][w + 2][ h + 2 ][w+2];
        
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                for( int ii = 0 ; ii < h ; ++ii ){
                    for( int jj = 0 ; jj < w ; ++jj ){
                        seen[i][j][ii][jj] = 1<<30;
                    }
                }
            }
        }
        seen[xini][yini][xbox][ybox] = 0;
        int mini = 1<<30;
        while( !Q.empty() ){
            State cur = Q.front(); Q.pop();
            if( cur.xbox == xend && cur.ybox == yend ){
                mini = min(mini, cur.d);
            }
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = dx[i] + cur.x, ny = dy[i] + cur.y;
                if( valid(nx, ny, h, w) && grid[nx][ny] != '#' ){
                    if( nx == cur.xbox && ny == cur.ybox ){
                        int nx_box = cur.xbox+dx[i], ny_box = cur.ybox+dy[i];
                        if( valid(nx_box, ny_box, h , w) && grid[nx_box][ ny_box] != '#' && 
                            seen[cur.x][cur.y][cur.xbox][cur.ybox] + 1 < seen[nx][ny][nx_box][ny_box] ){
                            Q.push(State(nx, ny, nx_box, ny_box, seen[cur.x][cur.y][cur.xbox][cur.ybox] + 1 ));
                            seen[nx][ny][nx_box][ny_box] = seen[cur.x][cur.y][cur.xbox][cur.ybox] + 1 ;
                        }
                    }else if( seen[cur.x][cur.y][cur.xbox][cur.ybox] < seen[nx][ny][cur.xbox][cur.ybox] ){
                        Q.push(State(nx, ny, cur.xbox, cur.ybox, seen[cur.x][cur.y][cur.xbox][cur.ybox]));
                        seen[nx][ny][cur.xbox][cur.ybox] = seen[cur.x][cur.y][cur.xbox][cur.ybox];
                    }
                }
            }
        }

        if( mini == 1<<30 ) mini = -1;
        return mini;
    }
};
