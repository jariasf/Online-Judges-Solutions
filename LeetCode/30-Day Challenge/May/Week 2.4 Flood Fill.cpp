/*******************************************
 ***Problema: Flood Fill
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: BFS | DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pii> Q;
        Q.push(mp(sr,sc));
        int val = image[sr][sc], h = image.size(), w = image[0].size();
        if( val == newColor ) 
            return image;
        while( !Q.empty() ){
            pii p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            image[x][y] = newColor;
            if( x - 1 >= 0 && image[x - 1][y] == val )
                Q.push(make_pair(x - 1, y));
            
            if( x + 1 < h && image[x + 1][y] == val )
                Q.push(make_pair(x + 1, y));
            
            if( y - 1 >= 0 && image[x][y - 1] == val )
                Q.push(make_pair(x, y - 1));
            
            if( y + 1 < w && image[x][y + 1] == val )
                Q.push(make_pair(x, y + 1));
        }
        return image;
    }
};
