/*******************************************
 ***Problema: Non-decreasing Subsequences
 ***ID: Week 3.6
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> current, int pos, vector<int> &v){
        int n = v.size();
        if( pos == n ){
            if(current.size() > 1)
                res.push_back(current);
            return;
        }

        if( current.empty() || v[pos] != current.back() ){
            solve(res, current, pos + 1, v);
        }

        if( current.empty() || v[pos] >= current.back() ){
            current.push_back(v[pos]);
            solve(res, current, pos + 1, v);
            current.pop_back();
        }
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> cur;
        solve(res, cur, 0, nums);
        return res;
    }
};
