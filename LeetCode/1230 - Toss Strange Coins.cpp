/*******************************************
 ***Problema: Toss Strange Coins 
 ***ID: 1230
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<double> p;
    vector<vector<double> > dp;
    double solve(int pos, int target){
        if( pos == p.size() ){
            if(target == 0 ){
                return 1;
            }else
                return 0;
        }
        if( target < 0 ){
            return 0;
        }
        
        if( dp[pos][target] != -1 ){
            return dp[pos][target];
        }
        return dp[pos][target] = p[pos] * solve(pos + 1, target - 1) + (1. - p[pos]) * solve(pos + 1, target); 
    }
    
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        p = prob;
        dp = vector<vector<double> >(n + 5, vector<double>(target + 5, -1));
        return solve(0, target);
    }
};
