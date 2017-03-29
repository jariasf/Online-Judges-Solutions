/*****************************************
 ***Problema: Beverages
 ***ID: 11060
 ***Juez: UVA
 ***Tipo: Graph Theory, Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define MAX 105

char cities[ MAX ][ 40 ];
int numcities;
int get_Id( char *s ){

    for( int i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

int let[ MAX ];
struct node{
    int x;
};

class comp{
   public:
   bool operator() ( const node &a, const node &b)
   {
       return a.x > b.x;
   }
};

int main(){
    int n , m , q = 1;
    char s1[ 52 ], s2[ 52 ];
    int inDegree [ MAX ], idx;

    while( scanf( "%d" , &n ) != EOF ){

        memset (inDegree, 0, sizeof( inDegree ) );
        idx = 0;
        numcities = 0;
        vector <int> ady[ n + 1 ];
        for( int i = 0 ; i < n ; ++i ){ scanf("%s" , cities[ i ] ); let[ idx++ ] = get_Id( cities[ i ] ); }

        scanf("%d" , &m );
        while( m-- ){
            scanf("%s %s" , s1 , s2 );
            int b = get_Id( s2 );
            ady[ get_Id( s1 ) ].push_back( b );
            inDegree [ b ]++;
        }
        printf("Case #%d: Dilbert should drink beverages in this order:" , q++ );

        priority_queue< node , vector<node > , comp > Q;
        node t;
        for ( int i = 0; i < numcities; i++ ) {
            if ( inDegree [ i ] == 0 ){
                t.x = i;
                Q.push( t );
            }
        }

        vector <int> sortedList;

        while ( !Q.empty () ) {
            t = Q.top();
            Q.pop ();
            int pop = t.x;
            sortedList.push_back ( pop );
            for ( unsigned int i = 0; i < ady[ pop ].size (); ++i ) {
                inDegree [ ady[ pop ] [ i ] ]--;
                if ( inDegree [ ady[ pop ] [ i ] ] == 0 )
                {
                    node aux;
                    aux.x = ady[ pop ][ i ];
                    Q.push ( aux);
                }
            }
        }

        for ( unsigned int i = 0; i < sortedList.size (); i++ ){
            printf(" %s" , cities[ sortedList[ i ] ] );
        }
        printf(".\n\n");

    }

    return 0;
}

