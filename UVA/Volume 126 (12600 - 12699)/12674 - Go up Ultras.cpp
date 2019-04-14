/*****************************************
 ***Problema: Go up Ultras
 ***ID: 12674
 ***Juez: UVA
 ***Tipo: RMQ + Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100005

#define MAXI( a , b ) (a>b)?a:b
int n, h[ MAX ];

int MIN( int a , int b ){ return (a<b)?a:b; }

int tree2[100001][20];
int loga[300001];

void rmq_init(){
    for(int i=0;i<n;i++)tree2[i][0]=h[i];
    for(int i=1;i<=16;i++)
        for(int j=0;j+(1<<i)-1<=n;j++)
            tree2[j][i]=MIN(tree2[j][i-1], tree2[j+(1<<(i-1))][i-1]);
}

int rmq_query(int a,int b){
    int k=b-a+1;
    return MIN(tree2[a][loga[k]], tree2[b+1-(1<<loga[k])][loga[k]] );
}

void rmq2_init(){
    for(int i=0;i<n;i++)tree2[i][0]=h[i];
    for(int i=1;i<=16;i++)
        for(int j=0;j+(1<<i)-1<=n;j++)
            tree2[j][i]=MAXI(tree2[j][i-1], tree2[j+(1<<(i-1))][i-1]);
}

int rmq2_query(int a,int b){
    int k=b-a+1;
    return MAXI(tree2[a][loga[k]], tree2[b+1-(1<<loga[k])][loga[k]] );
}

int l[ MAX ] , r[ MAX ] , ultra[ MAX ];

struct Data{
    int h , idx;
    Data( int hh , int ii ) : h( hh ) , idx(ii){}
};
int main(){
    loga[1]=0;
    for(int i=1;i<=16;i++)
        for(int j=(1<<i);j<(1<<(i+1));j++)
            loga[j]=i;

    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n && scanf("%d" , &h[ i ] ) ; ++i );
        l[ 0 ] = -1;
        for( int i = 1 ; i < n ; ++i ){
            l[ i ] = i - 1;
            while( l[ i ] >= 0 && h[ i ] >= h[ l[ i ] ] ){
                l[ i ] = l[ l[ i ] ];
            }
            if( h[ l[ i ] ] == h[ i ] )
                l[ i ] = 0;
        }

        r[ n - 1 ] = n;
        for( int i = n - 2 ; i >= 0 ; --i ){
            r[ i ] = i + 1;
            while( r[ i ] < n && h[ i ] >= h[ r[i] ] ){
                r[ i ] = r[ r[ i ] ];
            }
            if( h[ r[ i] ] == h[ i ])
                r[ i]  = 0;
        }
        
        rmq_init();
        int len = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( i - 1 >= 0 && i + 1 < n && h[ i ] > h[ i + 1 ] && h[ i ] > h[ i - 1 ] ){
                int near_left = l[ i ] , near_right = r[ i ];
                int mini = rmq_query( near_left , i );
                if( h[ i ] - mini < 150000 ) continue;
                mini = rmq_query( i , near_right );
                if( h[ i ] - mini < 150000 ) continue;
                ultra[ len++ ] = i;
            }
        }

        for( int i = 0 ; i < len ; ++i ){
            if( i ) printf(" ");
            printf("%d" , ultra[ i] + 1 );
        }
        printf("\n");
    }

    return 0;
}
