/*******************************************
 ***Problema: Combination Sum
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &current, vector<int>& candidates, int pos, int target ){
        if( target == 0 ){
            res.push_back(current);
            return;
        }

        if( target < 0 ) return;
        for( int i = pos ; i < candidates.size(); ++i ){
            current.push_back(candidates[i]);
            solve( res, current, candidates, i, target - candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> current;
        solve(res,current,candidates,0,target);
        return res;
    }
};
