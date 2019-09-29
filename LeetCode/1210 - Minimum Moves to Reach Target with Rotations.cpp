/*******************************************
 ***Problema: Minimum Moves to Reach Target with Rotations
 ***ID: 1210
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define RIGHT 0
    #define DOWN 1
    #define MAX 101
    struct State{
        int x, y, dir, d;
        State(int _x , int _y, int _dir, int _d): x(_x), y(_y), dir(_dir), d(_d){}
        State(){}
    };
    bool seen[MAX][MAX][5];
    int minimumMoves(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        
        queue<State> Q;
        Q.push(State(0, 1, RIGHT, 0));
        memset(seen , 0 ,sizeof(seen));
        seen[0][1][RIGHT] = true;
        
        while( !Q.empty() ){
            State cur = Q.front(); Q.pop();
            int x = cur.x, y = cur.y, dir = cur.dir, d = cur.d;
            if( x == h - 1 && y == w - 1 && dir == RIGHT ) return d;
            
            if( dir == RIGHT ){
                //Right
                if( y + 1 < w && grid[x][y + 1] == 0 && !seen[x][y + 1][RIGHT] ){
                    seen[x][y + 1][RIGHT] = true;
                    Q.push(State(x, y + 1, RIGHT, d + 1));
                }
                
                if( x + 1 < h && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0){
                    //Down
                    if( !seen[x + 1][y][RIGHT] ){
                        seen[x + 1][y][RIGHT] = true;
                        Q.push(State(x + 1, y, RIGHT, d + 1));
                    }
                    
                    //Clockwise
                    if( !seen[x + 1][y - 1][DOWN] ){
                        seen[x + 1][y - 1][DOWN] = true;
                        Q.push(State(x + 1, y - 1, DOWN, d + 1));
                    }
                }
                
                
            }else if(dir == DOWN){
                //Down
                if(x + 1 < h && grid[x + 1][y] == 0 && !seen[x + 1][y][DOWN] ){
                    seen[x + 1][y][DOWN] = true;
                    Q.push(State(x + 1, y, DOWN, d + 1));
                }
                
                if( y + 1 < w && grid[x - 1][y + 1] == 0 && grid[x][y + 1] == 0){
                    //Right
                    if( !seen[x][y + 1][DOWN] ){
                        seen[x][y + 1][DOWN] = true;
                        Q.push(State(x, y + 1, DOWN, d + 1));
                    }
                    
                    //Anti-clockwise
                    if( !seen[x - 1][y + 1][RIGHT] ){
                        seen[x - 1][y + 1][RIGHT] = true;
                        Q.push(State(x - 1, y + 1, RIGHT, d + 1));
                    }
                }
            }
            
        }
        return -1;
    }
};
