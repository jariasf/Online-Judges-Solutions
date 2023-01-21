/*******************************************
 ***Problema: Restore IP Addresses
 ***ID: Week 3.7
 ***Juez: LeetCode
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void solve(vector<string> &v, string current, int num, string &s, int pos, int cnt){
        if( cnt > 4 ) return;
        int n = s.size();        
        if( pos == n){
            if( cnt == 4) v.push_back(current);
            return;
        }
        
        int next = num * 10 + (s[pos] - '0'); 
        if( next <= 255 && (pos == 0 || num > 0) )
            solve(v, current + s[pos], next, s, pos + 1, cnt);
        if(pos > 0)
            solve(v, current + "." + s[pos], s[pos] - '0', s, pos + 1, cnt + 1);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() > 12) return res;        
        string current = "";
        solve(res, current, 0, s, 0, 1);
        return res;
    }
};
