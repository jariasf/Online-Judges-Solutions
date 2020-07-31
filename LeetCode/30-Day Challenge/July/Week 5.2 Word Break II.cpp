/*******************************************
 ***Problema: Word Break II
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    unordered_set<string> hash;
    unordered_map<int, vector<string> > dp;
    vector<string> solve(string &s, int start){
        vector<string> res;
        if( start == s.size() ){
            res.push_back("");
            return res;
        }

        if( dp.find(start) != dp.end() )
            return dp[start];
        
        string sub = "";
        for( int i = start; i < s.size(); ++i ){
            sub += s[i];
            if( hash.find(sub) != hash.end() ){
                vector<string> v = solve(s, i + 1);
                for(string cur: v){
                    if( cur.size() > 0 )
                        res.push_back(sub + " " + cur);
                    else
                        res.push_back(sub);
                }
            }
        }
        
        return dp[start] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        hash.clear();
        for(string s:wordDict)
            hash.insert(s);
        dp.clear();
        return solve(s, 0);
    }
};
