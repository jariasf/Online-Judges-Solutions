/*******************************************
 ***Problema: Jump Game IV
 ***ID: 1345
 ***Juez: LeetCode
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define INF 1<<30

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int> > hash_pos;
        for( int i = 0 ; i < n ; ++i )
            hash_pos[ arr[i] ].push_back(i);
        
        queue<int> Q;
        Q.push(0);
        vector<int> seen(n + 5, INF);
        seen[0] = 0;
        while( !Q.empty() ){
            int cur = Q.front(); Q.pop();
            if( cur == n - 1 ) break;
            if( cur + 1 < n && seen[ cur + 1 ] > seen[ cur ] + 1 ){
                seen[ cur + 1 ] = seen[ cur ] + 1;
                Q.push( cur + 1 );
            }
            if( cur - 1 >= 0 && seen[ cur - 1 ] > seen[ cur ] + 1 ){
                seen[ cur - 1 ] = seen[ cur ] + 1;
                Q.push( cur - 1 );
            }
            
            vector<int> idx = hash_pos[ arr[cur] ];
            for( int i = 0 ; i < idx.size(); ++i ){
                if( idx[i] != cur && seen[ idx[i] ] > seen[ cur ] + 1 ){
                    seen[ idx[i] ] = seen[ cur ] + 1;        
                    Q.push(idx[i]);
                }
            }
            hash_pos[arr[cur]].clear();
        }
        return seen[n - 1];
    }
};
