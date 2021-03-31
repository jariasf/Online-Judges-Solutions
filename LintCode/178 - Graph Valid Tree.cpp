/*******************************************
 ***Problema: Graph Valid Tree
 ***ID: 178
 ***Juez: LintCode
 ***Tipo: DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    vector<vector<int> > adj;
    vector<bool> visited;
    bool hasCycle(int u, int p=-1){
        visited[u] = true;
        for( int v: adj[u] ){
            if( !visited[v] ){
                if( hasCycle(v, u) ) return true;
            }else if( p != v ){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        adj = vector<vector<int> >(n);
        for(vector<int> e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);            
        }
        visited = vector<bool>(n);
        if( hasCycle(0) ) return false;
        for(int i = 0 ; i < n ; ++i )
            if( visited[i] == false )
                return false;
        return true;
    }
};
