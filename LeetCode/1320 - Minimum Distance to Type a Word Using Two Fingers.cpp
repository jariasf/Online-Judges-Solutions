/*******************************************
 ***Problema: Minimum Distance to Type a Word Using Two Fingers
 ***ID: 1320
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    pii getPos(int id){
        return mp(id/6, id%6);
    }
    
    int dist(pii p1, pii p2){
        int x1 = p1.first,  y1 = p1.second,  x2 = p2.first,  y2 = p2.second;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    vector<int> val;
    #define MAX 30
    int dp[305][MAX][MAX];
    int distance(int pos_x, int pos_y){
        if( pos_y == 26 ) return 0;
        pii p1 = getPos(pos_x), p2 = getPos(pos_y);
        return dist(p1, p2);
    }

    string word;
    int solve(int pos, int pos_x, int pos_y){
        if(pos == word.size() ) return 0;
        if( dp[pos][pos_x][pos_y] != -1 ) return dp[pos][pos_x][pos_y];
        int cur = word[pos] - 'A';
        int a = distance(cur, pos_x) + solve(pos + 1, cur, pos_y);
        int b = distance(cur, pos_y) + solve(pos + 1, pos_x, cur);
        int res = min(a, b);
        return dp[pos][pos_x][pos_y] = res;
    }
    
    int minimumDistance(string _word) {
        word = _word;
        int n = word.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26);
    }
};
