/*******************************************
 ***Problema: Alien Dictionary
 ***ID: 269
 ***Juez: LeetCode
 ***Tipo: Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param words: a list of words
     * return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        int n = words.size();
        vector<int> degree(26);
        vector<bool> seen(26);
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < words[i].size(); ++j )
                seen[words[i][j] - 'a'] = 1;
        
        int V = 0;
        for( int i = 0 ; i < 26 ; ++i )
            if( seen[i] ) V++;
        
        vector<vector<int> > adj = vector<vector<int>>(26, vector<int>());
        for( int i = 0 ; i < n - 1 ; ++i ){
            int len = min(words[i].size(), words[i + 1].size());
            for( int j = 0 ; j < len ; ++j ){
                if( words[i][j] != words[i + 1][j]){
                    adj[ words[i][j] - 'a' ].push_back( words[i + 1][j] - 'a');
                    degree[ words[i + 1][j] - 'a']++;
                    break;
                }
            }
        }
        
        priority_queue<int, vector<int>, greater<int> > Q;
        for( int i = 0 ; i < 26 ; ++i ){
            if( degree[i] == 0 && seen[i] ){
                Q.push(i);
            }
        }
        
        string res = "";
        while( !Q.empty() ){
            int cur = Q.top(); Q.pop();
            res += (char)(cur + 'a');
            for( int i = 0 ; i < adj[cur].size(); ++i ){
                int next = adj[cur][i];
                if( --degree[next] == 0){
                    Q.push(next);
                } 
            }
        }
        if(Q.size() != 0 || res.size() != V ) return "";
        return res;
    }
};

/*
["abc","bcd","qwert","ab"]
["ab","adc"]
["zy","zx"]
*/
