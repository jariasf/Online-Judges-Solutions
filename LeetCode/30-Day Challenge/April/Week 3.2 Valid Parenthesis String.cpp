/*******************************************
 ***Problema: Valid Parenthesis String
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Greedy | Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Greedy
class Solution {
public:
    bool checkValidString(string s) {
        int maxDiff = 0 , minDiff = 0;
        for( int i = 0 ; i < s.size(); ++i ){
            if( s[i] == '('){
                minDiff++; maxDiff++;
            }else if( s[i] == ')'){
                minDiff--; maxDiff--;
            }else{
                maxDiff++;
                minDiff--;
            }
            if( maxDiff < 0 ) return false;
            minDiff = max(minDiff, 0);
        }
        return minDiff == 0;
    }
};


//DP
class Solution {
public:
    vector<vector<int> > dp;
    bool solve(int pos, int cnt, string &s){
        int n = s.size();

        if( cnt < 0 ) return false;
        if( pos == n )
            return cnt == 0;
        
        if( dp[pos][cnt] != -1 ) return dp[pos][cnt];
        
        bool res = 0;
        if( s[pos] == '(') res |= solve(pos + 1, cnt + 1, s);
        else if( s[pos] == ')') res |= solve(pos + 1, cnt - 1, s);
        else{
            res |= solve(pos + 1, cnt + 1, s) || solve(pos + 1, cnt - 1, s) || solve(pos + 1, cnt, s);
        }
        return dp[pos][cnt] = res;
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        dp = vector<vector<int> >(n, vector<int>(n + 1, -1));
        return solve(0, 0, s);
    }
};
