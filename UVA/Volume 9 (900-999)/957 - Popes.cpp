/*****************************************
 ***Problema: Popes
 ***ID: 957
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    int Y , P , x;
    while( scanf("%d %d" , &Y , &P ) == 2 ){
        queue<int> Q;
        int best[ 3 ] = { -1 , -1 , -1 };
        for( int i = 0 ; i < P ; ++i ){
            scanf("%d" , &x );
            Q.push( x );
            while( Q.size() > 0 && Q.back() - Q.front() >= Y ) Q.pop();

            if( (int)Q.size() > best[ 0 ] ){
                best[ 0 ] = Q.size();
                best[ 1 ] = Q.front();
                best[ 2 ] = Q.back();
            }
        }
        printf("%d %d %d\n" , best[ 0 ] , best[ 1 ] , best[ 2 ] );
    }
    return 0;
}
