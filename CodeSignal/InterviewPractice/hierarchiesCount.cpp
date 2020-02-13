/*******************************************
 ***Problema: Hierarchies Count
 ***Juez: CodeSignal
 ***Tipo: Modular Inverse + Determinant (Cayley's formula)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 105
const int MOD = 1e9 + 7;
const double eps = 1e-7;
typedef long long LL;

int extended_euclid( int a , int b , int &x , int &y ){
    if( b == 0 ){ x = 1; y = 0; return a; }
    int d = extended_euclid( b , a % b , y , x );
    y -= a/b * x;
    return d;
}

int mod( int a , int b ){
    return ( (a % b) + b ) % b;
}

int mod_inverse( int a , int n ){
   int x , y , d;
   d = extended_euclid( a , n , x , y );
   if( d > 1 ) return -1;
   return mod( x , n );
}

LL determinant( int N, vector<vector<LL> > &laplacian ){
    LL ans = 1 , aux;
    bool found;
    for( int i = 0 , r = 0 ; i < N ; ++i ){
        found = false;
        for( int j = r ; j < N ; ++j ){
            if( laplacian[j][i] > 0 ){
                found = true;
                if( j > r ) ans = -ans;
                else break;
                for( int k = 0 ; k < N ; ++k ) 
                    swap( laplacian[ r ][ k ] , laplacian[ j ][ k ] );
                break;
            }
        }
        if( found ){
            for( int j = r + 1 ; j < N ; ++j ){
                aux = (laplacian[ j ][ i ] * 
                       mod_inverse( laplacian[r][i] , MOD ) % MOD);
                for( int k = i ; k < N ; ++k ) {
                    laplacian[j][k] -= aux * laplacian[ r ][ k ] % MOD;
                    laplacian[j][k] = mod(laplacian[j][k], MOD);
                }
            }
            r++;
        }else 
            return 0;
    }
    for( int i = 0 ; i < N ; ++i ){
        ans = (ans * laplacian[i][i] % MOD) % MOD;
    }
    return ans;
}

int hierarchiesCount(int n, std::vector<std::vector<int>> respectList) {
    vector<vector<LL> > laplacian(n, vector<LL>(n, 0));
    for( int i = 0 ; i < respectList.size(); ++i ){
        int u = respectList[i][0], v = respectList[i][1];
        laplacian[u][u]++;
        laplacian[v][v]++;
        laplacian[u][v] = laplacian[v][u] = -1;
    }
    return (determinant(n - 1, laplacian)  * n) % MOD;
}

