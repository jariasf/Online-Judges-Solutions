/*******************************************
 ***Problema: Smallest String With Swaps
 ***ID: 1202
 ***Juez: LeetCode
 ***Tipo: DFS|BFS + Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<char,int>
    #define mp make_pair

    vector<bool> seen;
    vector<vector<int> > ady;
    unordered_map<int, vector<pii> > hash;
    string S;
    void dfs(int u, int comp){
        hash[comp].push_back( mp(S[u], u));
        seen[u] = true;
        for( int i = 0 ; i < ady[u].size(); ++i ){
            int v= ady[u][i];
            if( !seen[v] ){
                dfs(v, comp);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int np = pairs.size();
        int n = s.size();
        S = s;
        seen = vector<bool>(n + 5);
        ady = vector<vector<int> >(n);
        for( int i = 0 ; i < np ; ++i ){
            int u = pairs[i][0], v = pairs[i][1];
            ady[u].push_back(v);
            ady[v].push_back(u);
        }
        
        int num_comp = 0;
        for( int i = 0 ; i< n ; ++i ){
            if( !seen[i] ){
                dfs(i, num_comp++);
            }
        }
        
        for( auto it:hash ){
            vector<pii> v = it.second;
            vector<char> vc(v.size());
            vector<int> vi(v.size());
            for( int i = 0 ; i < v.size(); ++i ){
                vc[i] = v[i].first;
                vi[i] = v[i].second;
            }

            sort(vc.begin(), vc.end() );
            sort(vi.begin(), vi.end());
            for( int i = 0 ; i < v.size(); ++i ){
                s[ vi[i] ] = vc[i];
            }
        }
        return s;
    }
};
