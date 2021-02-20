/*******************************************
 ***Problema: Tree of Coprimes
 ***ID: 1766
 ***Juez: LeetCode
 ***Tipo: DFS + Coprimes
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int, int>
    #define mp make_pair
    int gcd(int a,int b){
        return  (b==0)? a:gcd(b,a%b);
    }
    
    vector<vector<int> > cop;
    void coprimes(){
        cop = vector<vector<int> >(55);
        for( int i = 1 ; i <= 50; ++i ){
            for( int j = 1 ; j <= 50 ; ++j ){
                if( gcd(i, j) == 1 ){
                    cop[i].push_back(j);
                }
            }
        }
    }
    
    vector<vector<int> > adj;
    vector<int> res, nums;
    vector<vector<pii> > path;
    void dfs(int u, int p, int depth ){        
        int maxi = -1;
        for( int i = 0 ; i < cop[ nums[u] ].size() ; ++i ){
            int coprime = cop[nums[u]][i];
            if( path[coprime].size() > 0 ){
                pii cur = path[coprime].back();
                int d = cur.first, idx = cur.second;
                if( maxi < d ){
                    maxi = d;
                    res[u] = idx;
                }
            }
        }
        path[nums[u]].push_back(mp(depth, u));
        for( int v: adj[u] ){
            if( v != p )           
                dfs(v, u, depth + 1);
        }
        path[nums[u]].pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        int n = nums.size();
        coprimes();
        res = vector<int>(n, -1);
        adj = vector<vector<int> >(n+2);
        for( int i = 0 ; i < edges.size(); ++i ){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        path = vector<vector<pii> >(55);
        dfs(0, -1, 0); 
        return res;
    }
};
