/**********************************************
 ***Problema: Internet Bandwidth
 ***ID: 820
 ***Juez: UVA
 ***Tipo: Graph Theory, Max Flow(Edmonds Karp)
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/**
u: nodo origen
v: nodo destino
c: capacidad de nodo u a v
r: indice de arista inversa, ejemplo si arista act 1->2 retorno es 1<-2
**/
struct Edge{
    int u;
    int v;
    int c;
    int r;
    Edge( int uu, int vv, int cc, int rr): u(uu), v(vv), c(cc), r(rr){}
};

vector< Edge > E;
vector< vector<int> > ady; //posee indices de aristas

int maxflow( int source , int sink ){

    for( int f = 0; ;){
        ///vector de enlaces previos para ver la ruta recorrida del argumenting path
        ///tiene indices de aristas
        vector<int> prev( ady.size() , -1 );
        queue<int> Q;
        Q.push( source );

        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            for( int i = 0 ; i < ady[ u ].size(); ++i ){
                 ///indice de arista actual
                 int e = ady[ u ][ i ];
                 int v = E[ e ].v;
                 ///si no puede pasar o si ya fue visitado
                 if( E[ e ].c == 0 || prev[ v ] >= 0 )continue;
                 Q.push( v );
                 prev[ v ] = e;
            }
        }
        ///si ya no hay argumenting paths
        if( prev[ sink ] < 0 )return f;
        ///hallamos minima capacidad de argumentin path
        int c = 0x7fffffff;
        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            c = min( c  , E[ prev[ x ] ].c );//c <?= E[ prev[ x ] ].c;
        }
        ///para nodos de ida 1->2 restamos capacidad minima
        ///para nodos de vuevla 2<-1 sumamos capacidad minima
        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            E[ prev[ x ] ].c -= c;
            E[ E[ prev[ x ] ].r ].c += c;
        }
        f += c;

    }

}

///indices de aristas comienzan x cero
///si tengo 1->2 su indice es 0, si 1<-2 su indice es 1
///x tanto r de primero es 1, de segundo es 0

void add( int u , int v , int c , bool dirigido = true ){

    Edge e1( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e1 );
    ///capadidad 0 si es dirigido
    Edge e2( v , u , ( dirigido )? 0 : c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}

int main(){
    int  V, s, t, A, u , v, c, casos = 0;

    while( scanf("%d", &V) && V ){
         //if( casos )printf("\n");
         E.clear();
         ady = vector< vector<int> >( V + 1 , vector<int> () );
         scanf("%d %d %d" , &s, &t ,&A);

         while( A-- ){
             scanf("%d %d %d", &u, &v , &c);
             add( u , v , c , false );
         }
         printf("Network %d\n", ++casos);
         printf("The bandwidth is %d.\n\n", maxflow( s , t ) );
    }

    return 0;
}
