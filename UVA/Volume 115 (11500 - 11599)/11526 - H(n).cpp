/*****************************************
 ***Problema: H(n)
 ***ID: 11526
 ***Juez: UVA
 ***Tipo: Ad hoc, Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <math.h>

using namespace std;

long long H(int n){
    if( n < 1)return 0;
    long long res = 0, ant = n , aux , l = (long long)sqrt(n);
    for( int i = 1 ; i <= l ; ++i ){
        aux = n / i;
        res += aux + (ant - aux)*( i - 1 );
        ant = aux;
    }
    if(ant > l ) res += l;
    return res;

}

int main(){
    int t;long long n;
    scanf( "%d" , &t);
    while( t-- ){
        scanf ( "%lld" , &n );
        printf("%lld\n",H(n));
    }
    return 0;
}
