/*******************************************
 ***Problema: Minimum Jumps to Reach Home
 ***ID: 1654
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 100001
#define MVALUE 2005
#define LEFT 0
#define RIGHT 1
bool seen[MAX][2];
class Solution {
public:
    struct State{
        int x, dir, d;
        State(int _x, int _d, int _dir): x(_x), d(_d), dir(_dir){}
        State(){}
    };
    
    vector<bool> invalid;
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        invalid = vector<bool>(MAX);
        for( int i = 0 ; i < forbidden.size(); ++i ) invalid[ forbidden[i] ] = 1;
        queue<State> Q;
        memset(seen, 0 , sizeof(seen));
        Q.push(State(x, 0, LEFT));
        seen[x][LEFT] = 1;
        
        while( !Q.empty() ){
            State cur = Q.front(); Q.pop();
            if( cur.x == 0 ) return cur.d;
            
            if( cur.x - a >= 0 && !seen[cur.x - a][LEFT] && !invalid[ cur.x - a ] ){
                seen[cur.x - a][LEFT] = 1;
                if( cur.x - a == 0 ) return cur.d + 1;
                Q.push(State(cur.x - a, cur.d + 1, LEFT));
            }
            
            if( cur.x + b < MAX && !seen[cur.x + b][RIGHT] && cur.dir != RIGHT && !invalid[ cur.x + b ] ){
                seen[cur.x + b][RIGHT] = 1;
                Q.push(State(cur.x + b, cur.d + 1, RIGHT));
            }
        }
        return -1;
    }
};
