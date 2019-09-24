/*******************************************
 ***Problema: Shortest Bridge
 ***ID: 1708
 ***Juez: LintCode
 ***Tipo: DFS | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Solution using DFS + BFS on distances
class Solution {
public:
    
    struct Position{
        int x, y, comp;
        Position(int _x, int _y):x(_x), y(_y){}
        Position(){}
    };
    
    #define COMP (1<<30)
    #define INIT 10
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
    
    void floodfill(vector<vector<int>> &A, int x, int y, int comp, queue<Position> &Q){
        int h = A.size(), w = A[0].size();
        A[x][y] = comp;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                if( A[nx][ny] == 0 && comp == COMP){
                    Q.push(Position(nx, ny));
                    A[nx][ny] = INIT;
                }
                else if( A[nx][ny] == 1 )
                    floodfill(A, nx, ny, comp, Q);
            }
        }
    }
    
    int bfs(vector<vector<int> > &A, queue<Position> &Q ){
        int h = A.size(), w = A[0].size();
        while( !Q.empty() ){
            Position current = Q.front(); Q.pop();
            int x = current.x, y = current.y;
            for( int i = 0 ; i < 4 ; ++i ){
                int nx = x + dx[i], ny = y + dy[i];
                if( nx >= 0 && ny >= 0 && nx < h && ny < w){
                    if(A[nx][ny] == 0){
                        A[nx][ny] = A[x][y] + 1;
                        Q.push(Position(nx, ny));
                    }else if( A[nx][ny] == COMP + 1 ){
                        return A[x][y] + 1 - INIT;
                    }
                }
            }
        }
        return -1;
    }
    
    int ShortestBridge(vector<vector<int>> &A) {
        int h = A.size(), w = A[0].size();
        queue<Position> Q;
        int comp = COMP;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0; j < w ; ++j ){
                if( A[i][j] == 1 ){
                    floodfill(A, i, j, comp++, Q);
                }
            }
        }
        return bfs(A, Q);
    }
};




// Solution using DFS + Brute Force on distances
class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<pii> border[2];    
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void floodfill(vector<vector<int>> &A, int x, int y, int comp){
        int h = A.size(), w = A[0].size();
        A[x][y] = -1;
        
        bool zero = false;
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                if( A[nx][ny] == 0) zero = true;
                else if( A[nx][ny] == 1 )
                    floodfill(A, nx, ny, comp);
            }
        }
        
        if( zero ){
            border[comp].push_back( mp(x,y));
        }
    }
    
    int dist(pii p1, pii p2){
        return abs( p1.first - p2.first) + abs(p1.second - p2.second);
    }
    
    int ShortestBridge(vector<vector<int>> &A) {
        int h = A.size(), w = A[0].size();
         
        border[0].clear();
        border[1].clear();         

        int comp = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0; j < w ; ++j ){
                if( A[i][j] == 1 ){
                    floodfill(A, i, j, comp++);
                }
            }
        }
        int smallest = 1<<30;
        for( int i = 0 ; i < border[0].size() ; ++i ){
            for( int j = 0 ; j < border[1].size(); ++j  ){
                smallest = min( smallest, dist(border[0][i], border[1][j]) - 1 );
            }
        }
        
        return smallest;
    }
};
