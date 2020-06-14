/*******************************************
 ***Problema: Kth Ancestor of a Tree Node
 ***ID: 1483
 ***Juez: LeetCode
 ***Tipo: Binary Lifting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class TreeAncestor {
public:
    #define MAX 50005
    int n, kparent[ MAX ][ 18 ];
    TreeAncestor(int n, vector<int>& parent) {
        memset( kparent , -1 , sizeof( kparent ) );
        for( int i = 0 ; i < n ; ++i ) kparent[ i ][ 0 ] = parent[ i ];
        for( int j = 1 ; 1<<j <= n ; ++j )
            for( int i = 0 ; i < n ; ++i ){
                if( kparent[i][j - 1] >= 0 )
                    kparent[ i ][ j ] = kparent[ kparent[ i ][ j - 1 ] ][ j - 1 ];
            }
    }
    
    int getKthAncestor(int node, int k) {
        for( int i = 0 ; i <= 17; ++i){ 
            if( k & (1 << i) ){
                node = kparent[node][i]; 
                if( node == -1 ) 
                    return -1; 
            }
        } 
        return node; 
    }

};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
