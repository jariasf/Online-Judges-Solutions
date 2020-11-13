/*******************************************
 ***Problema: Permutations II
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Backtracking + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> cur, int pos ){
        if( pos == cur.size() ){
            res.push_back(cur);
            return;
        } 
        
        unordered_set<int> hash;
        for(int i = pos; i < cur.size(); ++i ){            
            if( hash.find( cur[i] ) != hash.end() ) continue;
            hash.insert(cur[i]);
            swap(cur[i], cur[pos]);            
            solve(res, cur, pos + 1);
            swap(cur[i], cur[pos]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        solve(res, nums, 0);
        return res;
    }
};
