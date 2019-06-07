/*******************************************
 ***Problema: Shortest Bridge
 ***ID: 934
 ***Juez: LeetCode
 ***Tipo: DFS, Flood-fill
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
class Solution {
public:
    int h, w;
    vector<pii> border[2];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<bool> > seen;
    void flood(int x, int y, int id, vector<vector<int>>& A ){
        seen[x][y] = 1;
        int cnt = 0;
        for( int i = 0 ; i < 4 ;++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && A[nx][ny] == 1 ){
                cnt++;
            }
        }
        
        if( cnt != 4 ){
            border[id].push_back( mp(x, y) );
        }
        
        for( int i = 0 ; i < 4 ;++i ){
            int nx = x + dx[i], ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && A[nx][ny] == 1 && !seen[nx][ny] ){
                flood(nx,ny, id, A);
            }
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& A) {
        h = A.size();
        w = A[0].size();
        seen = vector<vector<bool> > (h + 1, vector<bool>(w + 1, false));
        border[0].clear(); border[1].clear();
        int label = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( A[i][j] == 1 && !seen[i][j] ){
                    flood(i, j, label, A);
                    label++;
                }
            }
        }

        int result = 1<<30;
        for( int i = 0 ; i < border[0].size(); ++i ){
            int x = border[0][i].first, y = border[0][i].second;
            for( int j = 0 ; j < border[1].size(); ++j ){
                int x2 = border[1][j].first, y2 = border[1][j].second;
                result = min( result, abs(x2 - x) + abs(y2- y) - 1);
            }
        }
        return result;
    }
};
