/*******************************************
 ***Problema: Bricks Falling When Hit
 ***ID: 1014
 ***Juez: LintCode
 ***Tipo: BFS | DFS | Connected Components
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define START 2 
    #define VISITED -1
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        
        int h = grid.size(), w = grid[0].size();
        int n = hits.size();
        
        vector<int> result(n, -1);
        vector<int> border(n, 0);
        for( int i = 0 ; i < n ; ++i ){
            int x = hits[i][0], y = hits[i][1];
            if( grid[x][y] > 1 || grid[x][y] == 0 ){
                result[i] = 0;
                continue;
            }
            grid[x][y] = i + START;
            if(x == 0) border[i] = 1;
        }
        
        queue<pair<int,int> > Q;
        for( int i = 0 ; i < w ; ++i ){
            if( grid[0][i] == 1 ){
                Q.push(make_pair(0, i));
                grid[0][i] = VISITED;
            }
        }
        
        while( !Q.empty() ){
            pair<int,int> p = Q.front(); Q.pop();
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                    if( grid[nx][ny] == 1 ){
                        grid[nx][ny] = VISITED;
                        Q.push(make_pair(nx, ny));
                    }else if( grid[nx][ny] > 1 ){
                        border[ grid[nx][ny] - START ] = 1;
                    }
                }
            }
        }
        
        for( int i = n - 1 ; i >= 0 ; --i ){
            int x = hits[i][0], y = hits[i][1]; 
            if( !border[i] ) result[i] = 0;
            if( result[i] == 0 ){
                if( grid[x][y] != 0 ) grid[x][y] = 1;
                continue;
            }
            
            Q.push(make_pair(x, y));
            grid[x][y] = VISITED;
            int cnt = 0;
            while( !Q.empty() ){
                pair<int,int> p = Q.front(); Q.pop();
                for( int i = 0 ; i < 4 ; ++i ){
                    int nx = p.first + dx[i], ny = p.second + dy[i];
                    if( nx >= 0 && ny >= 0 && nx < h && ny < w){
                        if( grid[nx][ny] == 1 ){
                            grid[nx][ny] = VISITED;
                            Q.push(make_pair(nx, ny));
                            cnt++;
                        }else if( grid[nx][ny] > 1 ){
                            border[ grid[nx][ny] - START ] = 1;
                        }
                    }
                }
            }
            result[i] = cnt;
        }
        
        return result;
    }
};
