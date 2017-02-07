/*****************************************
 ***Problema: M*A*S*H
 ***ID: 402
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int n , l , deck[ 21 ] , q = 1;
    bool first;
    while( scanf("%d %d" , &n , &l ) == 2 ){
        vector<int> Circle;
        for( int i = 0 ; i < 20 ; ++i )scanf("%d" , &deck[ i ] );
        for( int i = 1 ; i <= n ; ++i ) Circle.push_back( i );

        for( int card = 0, persons = n ; persons > l && card < 20 ; ++card ){
            //para cada carta hago josehpus hasta la persona N
            int i = 0, next;
            while( i < Circle.size() && persons > l ){
                next = ( i + deck[ card ] - 1 );
                if( next >= Circle.size() || persons <= l ) break;
                Circle.erase( Circle.begin() + next );
                persons--;
                i = next;
            }
        }
        first = true;
        printf("Selection #%d\n" , q++ );
        for( int i = 0 ; i < Circle.size() ; ++i ){
            if( !first ) printf(" ");
            printf("%d" , Circle[ i ] );
            first = false;
        }
        printf("\n\n");
    }
    return 0;
}
