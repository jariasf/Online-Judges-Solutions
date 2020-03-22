/*******************************************
 ***Problem: Check if There is a Valid Path in a Grid
 ***ID: 1391
 ***Judge: LeetCode
 ***Type: Union Find | Graph Traversal
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct State{
        vector<vector<int> > dir;
        vector<vector<int> > valid;
        State( vector<vector<int> > d, vector<vector<int> > v ){
            dir = d;
            valid = v;
        }
        State(){}
    };

    State v[7];
    void init(){
        v[1] = State( {{0, -1}, {0, 1}} , {{1, 4, 6}, {1, 3, 5}});
        v[2] = State( {{-1, 0}, {1, 0}} , {{2, 3, 4}, {2, 5, 6}});
        v[3] = State( {{1, 0}, {0, -1}} , {{2, 5, 6}, {1, 4, 6}});        
        v[4] = State( {{1, 0}, {0, 1}} , {{2, 5, 6}, {1, 3, 5}});
        v[5] = State( {{0, -1}, {-1, 0}} , {{1, 4, 6}, {2, 3, 4}});
        v[6] = State( {{0, 1}, {-1, 0}} , {{1, 3, 5}, {2, 3, 4}});        
    }
    
    bool validMove(int v, vector<int> &adj){
        for( int i = 0 ; i < adj.size(); ++i ){
            if( adj[i] == v ) return true;
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        init();
        int x = 0, y = 0;
        while(true){
            int val = grid[x][y];
            if( val == -1 ) break;
            State cur = v[val];
            bool valid = false;
            grid[x][y] = -1;            
            for( int i = 0 ; i < 2 ; ++i ){
                int nx = x + cur.dir[i][0];
                int ny = y + cur.dir[i][1];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] != -1 ){                    
                    if( validMove(grid[nx][ny], cur.valid[i])){
                        valid = true;
                        x = nx; y = ny;
                        break;
                    }
                }
            }
            if( !valid ) break;
        }
        return grid[h - 1][w - 1] == -1;
    }
};
