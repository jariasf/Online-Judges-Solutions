/*******************************************
 ***Problema: Combination Sum
 ***ID: 135
 ***Juez: LintCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > result;
    vector<int> candidates;
    void solve(int pos, int target, vector<int> current){
        if( target == 0 ){
            result.push_back(current);
            return;
        }
        if( pos == candidates.size() ) return;

        int j = pos + 1;
        while( j < candidates.size() && candidates[j] == candidates[pos]){
            j++;
        }    
        
        if( candidates[pos] <= target ){
            current.push_back(candidates[pos]);
            solve(pos, target - candidates[pos], current);
            current.pop_back();
        }
        solve(j, target, current);    
    }

    vector<vector<int>> combinationSum(vector<int> &_candidates, int target) {
        candidates = _candidates;
        sort(candidates.begin(), candidates.end());
        result.clear();
        vector<int> current;
        solve(0, target, current);
        return result;
    }
};
