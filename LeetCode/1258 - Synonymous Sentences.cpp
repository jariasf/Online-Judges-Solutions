/*******************************************
 ***Problema: Synonymous Sentences
 ***ID: 1258
 ***Juez: LeetCode
 ***Tipo: DFS|Union-Find + Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    vector<string> tokens;
    unordered_map<string, vector<string> > adj;
    unordered_set<string> sentences;

    // generation
    void solve(int pos, string res){
        if( pos == tokens.size() ){
            sentences.insert(res.substr(0, res.size() - 1));
            return;
        }
        
        solve(pos + 1, res + tokens[pos] + " ");
        vector<string> synom = adj[tokens[pos]];
        for( int i = 0 ; i < synom.size(); ++i ){
            solve(pos + 1, res + synom[i] + " ");
        }
    }
    
    unordered_set<string> seen;
    unordered_map<int, unordered_set<string> > comp;
    void dfs(string u, int i){
        if( comp[i].find(u) != comp[i].end() ) return;
        seen.insert(u);
        comp[i].insert(u);
        vector<string> v = adj[u];
        for( int j = 0 ; j < v.size(); ++j ){
            dfs( v[j], i);
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        stringstream ss(text);
        tokens.clear();
        adj.clear();
        string s;
        while(ss>>s ){
            tokens.push_back(s);
        }
        for( int i = 0 ; i < synonyms.size(); ++i ){
            adj[ synonyms[i][0] ].push_back( synonyms[i][1]);
            adj[ synonyms[i][1] ].push_back( synonyms[i][0]);
        }
        
        // Find connected components
        int cc = 0;
        seen.clear();
        comp.clear();
        for( auto it: adj){
            string u = it.first;
            if(seen.find(u) == seen.end() ){
                dfs(u, cc++);
            }
        }
        
        // Reconstruct Tree
        adj.clear();
        for(auto it:comp ){
            unordered_set<string> _s = it.second;
            vector<string> v(_s.begin(), _s.end() );
            for( int i = 0 ; i < v.size(); ++i ){
                for( int j = 0 ; j < v.size(); ++j ){
                    if(i == j ) continue;
                    adj[ v[i] ].push_back( v[j] );
                }
            }
        }

        sentences.clear();
        solve(0, "");
        vector<string> res( sentences.begin(), sentences.end() );
        sort(res.begin(), res.end());
        return res;
    }
};
