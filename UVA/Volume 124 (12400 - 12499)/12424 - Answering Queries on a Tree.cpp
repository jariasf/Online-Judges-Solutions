/*****************************************
 ***Problema: Answering Queries on a Tree
 ***ID: 12424
 ***Juez: UVA
 ***Tipo: Heavy-Light Decomposition + Segment Tree
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX 100010
int MAXI( int a , int b ){ return ( a < b ) ? b : a; }
int depth[ MAX ] , homeChain[ MAX ] , homePos[ MAX ] , chainLeader[ MAX ];
int treesize[ MAX ] , parent[ MAX ];
int pos , cntChain , n;
std::vector<int> ady[ MAX ];

///SEGMENT TREE
struct Node{
    int max, color[ 11 ];
    Node( int m ){
        memset( color , 0 , sizeof( color ) );
        max = m;
    }
    Node(){}
} tree[ 4 * MAX ];

void init(){
    for( int i = 0 ; i < MAX * 4 ; ++i ) tree[ i ] = Node( 0  );
}

void update( int pos , int by , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left == right){
        tree[ node ] = Node( 1 );
        tree[ node ].color[ by ] = 1;
        return;
    }
    int mid = ( left + right )>>1, L = 2 * node + 1 , R = 2 * node + 2;
    if( pos <= mid ) update( pos , by , left , mid , L );
    else update( pos , by , mid + 1 , right , R );
    tree[ node ] = Node( 0 );
    for( int i = 1 ; i < 11 ; ++i ) {
        tree[ node ].color[ i ] = tree[ R ].color[ i ] + tree[ L ].color[ i ];
    }
}

Node query( int from , int to , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left >= from && right <= to ){
        return tree[ node ];
    }
    int mid = ( left + right )>>1, L = 2 * node + 1 , R = 2 * node + 2;
    Node LL( 0 ) , RR( 0 ), ans(  0 );
    if( from <= mid ){
        LL = query( from , to , left , mid , L );
    }
    if( to > mid ){
        RR = query( from , to , mid + 1 , right , R );
    }
    for( int i = 1 ; i < 11 ; ++i ){
        ans.color[ i ] = LL.color[ i ] + RR.color[ i ];
    }
    return ans;
}
///FIN SEGMENT TREE

///HEAVY-LIGHT DECOMPOSITION
void dfs( int x  , int p , int lvl ){
    if( parent[ x ] != -1 ) return;
    parent[ x ] = p;
    treesize[ x ] = 1;
    depth[ x ] = lvl;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( ady[ x ][ i ] != p ){
            dfs( ady[ x ][ i ] , x , lvl + 1 );
            treesize[ x ] += treesize[ ady[ x ][ i ] ];
        }
    }
}

void heavy_light( int x , int parent , int idChain , int depth ){
    if( !depth ){
        idChain = cntChain++;
        chainLeader[ idChain ] = x;
    }
    homeChain[ x ] = idChain;
    homePos[ x ] = pos++;
    int maxi = -1;

    for( int i = 0 ; i < ady[ x ].size() ; ++i )
        if( ady[ x ][ i ] != parent &&
          ( maxi == -1 || treesize[ ady[ x ][ i ] ] > treesize[ ady[ x ][ maxi ] ] ) )
            maxi = i;

    if( maxi != -1 ) heavy_light( ady[ x ][ maxi ] , x , idChain , depth + 1 );

    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( ady[ x ][ i ] != parent && maxi != i )
            heavy_light( ady[ x ][ i ] , x , -1 , 0 );
    }
}

int solve( int p , int q ){
    int maxi = 0;
    Node aux( 0 ), suma( 0 );
    while( homeChain[ p ] != homeChain[ q ] ){
        if( depth[ chainLeader[ homeChain[ p ] ] ] < depth[ chainLeader[ homeChain[ q ] ] ] ){
            aux = query( homePos[ chainLeader[ homeChain[ q ] ] ] , homePos[ q ] );
            for( int i = 1 ; i < 11 ; ++i ){
                suma.color[ i ] += aux.color[ i ];
            }
            q = parent[ chainLeader[ homeChain[ q ] ] ];
        }
        else{
            aux = query( homePos[ chainLeader[ homeChain[ p ] ] ] , homePos[p ] );
            for( int i = 1 ; i < 11 ; ++i ){
                suma.color[ i ] += aux.color[ i ];
            }
            p = parent[ chainLeader[ homeChain[ p ] ] ];
        }
    }
    if( depth[ p ] < depth[ q ] ){
        aux = query( homePos[ p ] , homePos[ q ] );
        for( int i = 1 ; i < 11 ; ++i ){
            suma.color[ i ] += aux.color[ i ];
            maxi = MAXI( maxi , suma.color[ i ] );
        }
    }
    else{
        aux = query( homePos[ q ] , homePos[ p ] );
        for( int i = 1 ; i < 11 ; ++i ){
            suma.color[ i ] += aux.color[ i ];
            maxi = MAXI( maxi , suma.color[ i ] );
        }
    }
    return maxi;
}

int main(){
    int t , m , x , u , v, c , a[ MAX ];
    scanf("%d" , &t);
    while( t-- ){
        scanf("%d %d" , &n , &m );
        init();
        for( int i = 1 ; i <= n ; ++i ) scanf("%d" , &a[ i ] );
        for( int i = 0 ; i < n - 1 ; ++i ){
            scanf("%d %d" , &u , &v );
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }
        memset( parent , -1 , sizeof( parent ) );
        dfs( 1 , 0 , 0 );
        pos = cntChain = 0;
        heavy_light( 1 , 0 , -1 , 0 );
        for( int i = 1 ; i <= n ; ++i ) update( homePos[ i ] , a[ i ] );
        while( m-- ){
            scanf("%d %d %d" , &c ,&u , &v );
            if( !c ){
                update( homePos[ u ] , v );
            }else{
                printf( "%d\n" , solve( u , v ) );
            }
        }
        for( int i = 0 ; i <= n ; ++i ) ady[ i ].clear();
    }
    return 0;
}

/*
test
2

7 6
3 3 2 2 3 2 3
1 2
2 3
2 4
1 5
5 6
5 7
1 3 5
0 1 1
0 2 1
1 3 5
0 2 4
1 2 4




2
5 6
3 2 1 2 3
1 2
2 3
2 4
1 5
1 3 5
0 1 1
0 2 1
1 3 5
0 2 4
1 2 4
22 21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
5 10
5 11
6 12
7 13
8 14
11 15
13 16
13 17
14 18
14 19
16 20
17 21
17 22
1 1 20
0 1 5
1 1 20
0 17 3
0 21 3
0 22 3
1 21 22
1 21 21
0  12 2
1 12 2
0 6 2
1 12 2
1 5 7
1 15 19
//
6
5
3
1
2
2
4
8

*/
