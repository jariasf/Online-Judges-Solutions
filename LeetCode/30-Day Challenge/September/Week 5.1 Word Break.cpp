/*******************************************
 ***Problema: Word Break
 ***ID: Week5.1
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> Q;
        Q.push(0);
        vector<bool> visited(s.size() + 1);
        visited[0] = 1;
        while( !Q.empty() ){
            int current = Q.front(); Q.pop();
            for( int i = 0 ; i < wordDict.size(); ++i ){
                int next = current + wordDict[i].size();
                if( !visited[next] && s.substr(current, wordDict[i].size()) == wordDict[i] ){
                    visited[next] = 1;
                    Q.push(next);
                }
            }
        }
        return visited[s.size()];
    }
};
