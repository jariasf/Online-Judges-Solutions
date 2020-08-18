/*******************************************
 ***Problema: Numbers With Same Consecutive Differences
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: DFS | BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void solve(vector<int> &res, int N, int K, int val){
        if( N == 0 ){
            res.push_back(val);
            return;
        }
        int last = val % 10;
        if( last - K >= 0 )
            solve(res, N - 1, K, val * 10 + last - K);
        if( last + K <= 9 && K != 0)
            solve(res, N - 1, K, val * 10 + last + K);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        if( N == 1 ) res.push_back(0);
        for( int i = 1 ; i < 10 ; ++i )
            solve(res, N - 1, K, i);
        return res;
    }    
};
