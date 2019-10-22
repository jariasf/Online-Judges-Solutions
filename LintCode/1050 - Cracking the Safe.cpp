/*******************************************
 ***Problema: Cracking the Safe
 ***ID: 1050
 ***Juez: LintCode
 ***Tipo: Bruijn Sequence, DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: n
     * @param k: k
     * @return: Cracking the Safe
     */
     
    unordered_set<string> visited;
    int total, n, k;
    bool dfs(string &s){
        if(visited.size() == total ){
            return true;
        }
        
        string suffix = s.substr(s.size() - n + 1);
        for( int i = 0 ; i < k ; ++i ){
            char digit = (char)('0' + i);
            string tmp = suffix + digit;
            if( visited.find(tmp) == visited.end() ){
                visited.insert(tmp);
                s.push_back(digit);
                if(dfs(s)) return true;
                s.pop_back();
                visited.erase(tmp);
            }    
        }
        return false;
    } 
     
     
    string crackSafe(int _n, int _k) {
        n = _n;
        k = _k;
        visited.clear();
        string res = "0";
        total = k;
        for( int i = 1 ; i < n ; ++i ){
            total *= k;
            res += '0';
        }
        visited.insert(res);
        dfs(res);
        return res;
        
    }
};
