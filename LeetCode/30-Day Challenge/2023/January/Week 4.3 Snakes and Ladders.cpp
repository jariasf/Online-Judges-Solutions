/*******************************************
 ***Problema: Snakes and Ladders
 ***ID: Week 4.3
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair

    void getPos(int cur, int n, int &x, int &y){
        int x_tmp = (cur - 1)/n;
        x = n - 1 - x_tmp;
        y = (cur - 1) % n;
        if( x_tmp & 1 )
            y = n - 1 - y;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), goal = n*n, x, y, destination;
        queue<pii> Q;
        vector<bool> visited(goal + 1);
        visited[1] = true;
        Q.push(mp(1, 0));
        while(!Q.empty()){
            pii p = Q.front(); Q.pop();
            int curr = p.first, moves = p.second;
            if(curr == goal)
                return moves;
            
            int maxi = min(curr + 6, goal);
            for(int next = curr + 1 ; next <= maxi ; ++next ){
                getPos(next, n, x, y);
                if( board[x][y] != -1 ) destination = board[x][y];
                else destination = next;
                if( !visited[destination] ){
                    visited[destination] = 1;
                    Q.push(mp(destination, moves + 1));
                }
            }
        }
        return -1;
    }
};
