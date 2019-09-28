/*******************************************
 ***Problema: Shortest Path to Get All Keys
 ***ID: 864
 ***Juez: LeetCode
 ***Tipo: BFS - State (x, y, mask)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param grid: 
     * @return: The lowest number of moves to acquire all keys
     */
    struct State{
        int x, y, keys, d;
        State(int _x, int _y, int _keys, int _d ): x(_x), y(_y), keys(_keys), d(_d){}
        State(){}
    };
    #define MAX 35
    bool seen[MAX][MAX][(1<<7) + 1];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    int bitcount(int n ){
        int ones = 0;
        while(n){
            ones++;
            n = n & (n - 1);
        }
        return ones;
    }
    int bfs(vector<string> &grid, int xini, int yini, int tot_keys){
        int h = grid.size(), w = grid[0].size();
        memset(seen, 0 , sizeof(seen));
        queue<State> Q;
        Q.push(State(xini, yini, 0, 0));
        grid[xini][yini] = '.';
        seen[xini][yini][0] = true;
        while( !Q.empty() ){
            State cur = Q.front(); Q.pop();
            int x = cur.x, y = cur.y, keys = cur.keys, d = cur.d;
            if( bitcount(keys) == tot_keys ) return d;
            
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = x + dx[i], ny = y + dy[i];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != '#' ){
                    if( grid[nx][ny] == '.'){
                        if( !seen[nx][ny][keys] ){
                            Q.push(State(nx, ny, keys, d + 1));
                            seen[nx][ny][keys] = true;
                        }
                    }else if( 'a' <= grid[nx][ny] && grid[nx][ny] <='z' ){
                        int new_keys = keys | 1<<(grid[nx][ny] - 'a');
                        if( !seen[nx][ny][new_keys] ){
                            Q.push(State(nx, ny, new_keys, d + 1));
                            seen[nx][ny][new_keys] = true;
                        }
                    }else if( 'A' <= grid[nx][ny] && grid[nx][ny] <= 'Z' && (keys & (1<<(grid[nx][ny] - 'A') )) ){
                        if( !seen[nx][ny][keys] ){
                            Q.push(State(nx, ny, keys, d + 1));
                            seen[nx][ny][keys] = true;
                        }
                    }
                }
            }
            
        }
        return -1;
    } 
     
    int shortestPathAllKeys(vector<string> &grid) {
        int h = grid.size(), w = grid[0].size();
        int xini, yini, keys = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( grid[i][j] == '@'){
                    xini = i; yini = j;
                }else if( 'a' <= grid[i][j] && grid[i][j] <= 'z')
                    keys++;
            }
        }
        return bfs(grid, xini, yini, keys);
    }
};
