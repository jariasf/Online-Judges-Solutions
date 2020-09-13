/*******************************************
 ***Problema: Combination Sum III
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> cur, int last, int k, int n){
        if(n < 0 || k < 0 ) return;
        if( n == 0 && k == 0 ){
            res.push_back(cur);
            return;
        }
        for( ++last ; last <= 9 ; ++last ){
            cur.push_back(last);
            solve(res, cur, last, k - 1, n - last);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> cur;
        solve(res, cur, 0, k, n);
        return res;
    }
};
