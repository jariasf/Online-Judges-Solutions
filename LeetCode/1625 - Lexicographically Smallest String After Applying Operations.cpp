/*******************************************
 ***Problema: Lexicographically Smallest String After Applying Operations
 ***ID: 1625
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        unordered_set<string> seen;
        queue<string> Q;
        Q.push(s);
        string res = s;
        while( !Q.empty() ){
            string cur = Q.front(); Q.pop();
            if( res > cur ) res = cur;
            string tmp = cur;
            for( int i = 1 ; i < n ; i += 2 ){
                int d = (cur[i] - '0' + a) % 10;
                tmp[i] = (char)(d + '0');    
            }
            if( seen.find(tmp) == seen.end()  ){
                seen.insert(tmp);
                Q.push(tmp);
            }
            rotate(cur.begin(), cur.begin() + n - b, cur.end());
            if( seen.find(cur) == seen.end()  ){
                seen.insert(cur);
                Q.push(cur);
            }            
        }
        return res;
    }
};
