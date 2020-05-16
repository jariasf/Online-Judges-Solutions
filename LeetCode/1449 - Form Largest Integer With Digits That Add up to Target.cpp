/*******************************************
 ***Problema: Form Largest Integer With Digits That Add up to Target
 ***ID: 1449
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming + Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> v;
    vector<int> dp;
    int solve(int target){
        if( target == 0 )
            return dp[target] = 0;
        
        if( dp[target] != -1 ) return dp[target];
        int res = -(1<<30);
        int n = v.size();
        for( int i = 0 ; i < n ; ++i ){
            if( target >= v[i] ){
                res = max(res, 1 + solve(target - v[i]));
            }
        }
        return dp[target] = res;
    }
    
    string res;
    bool print(int target, int max_len, string cur){
        if(max_len == 0){
            res = cur;
            return true;
        }
        
        for( int i = v.size() - 1 ; i >= 0 ; --i ){
            if( target - v[i] >= 0 && 1 + dp[target - v[i]] == max_len ){
                if( print(target - v[i], max_len - 1, cur + to_string(i + 1) ) ) return true;
            }
        }
        return false;
    }    
    
    string largestNumber(vector<int>& cost, int target) {
        v = cost;
        dp = vector<int>(target + 5, -1);
        int max_len = solve(target);
        if( max_len < 0 ) return "0";
        res = "0";
        print(target, max_len, "");
        return res;
    }
};
