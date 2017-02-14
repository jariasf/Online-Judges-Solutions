/*****************************************
 ***Problema: Editor
 ***ID: 1223
 ***Juez: UVA
 ***Tipo: Suffix Array
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#define MAXN 5010
#define Clear(a) memset(a,0,sizeof(a))
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
using namespace std;


#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[ MAXN ] , wb[ MAXN ],wv[ MAXN ], wss[ MAXN ];
int LCP[ MAXN ], pos[ MAXN * 3 ], rank[ MAXN ], r[ MAXN * 3 ];
char s[ MAXN ];

int c0(int r[],int a,int b) {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int r[],int a,int b) {
    if( k == 2 )
        return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void sort(int r[],int a[],int b[],int n,int m)
{
     int i;
     for( i = 0 ; i < n ; ++i ) wv[ i ] = r[ a[ i ] ];
     for( i = 0 ; i < m ; ++i ) wss[ i ] = 0;
     for( i = 0 ; i < n ; ++i ) wss[wv[i]]++;
     for( i = 1 ; i < m ; ++i ) wss[ i ] += wss[i-1];
     for( i = n - 1 ; i >= 0 ; --i ) b[--wss[wv[i]]]=a[i];
     return;
}

void dc3(int r[],int pos[],int n,int m)
{
     int i , j , *rn = r + n ,*san=pos+n,ta=0,tb=(n+1)/3,tbc=0,p;
     r[ n ] = r[ n + 1 ] = 0;
     for( i = 0 ; i < n ; ++i ) if( i % 3 != 0 ) wa[ tbc++ ]=i;
     sort( r + 2 , wa , wb , tbc , m );
     sort( r + 1 , wb , wa , tbc , m );
     sort( r , wa , wb , tbc , m );
     for( p = 1 , rn[ F( wb[ 0 ] ) ] = 0 ,i=1; i<tbc; ++i)
     rn[ F( wb[ i ] ) ] = c0( r , wb[i-1] , wb[i] )?p-1:p++;
     if( p < tbc ) dc3( rn , san , tbc , p );
     else for( i = 0 ; i < tbc ; ++i ) san[rn[i]] = i;
     for( i = 0 ; i < tbc; ++i )if(san[i]<tb) wb[ta++]=san[i]*3;
     if( n % 3 == 1 ) wb[ta++] = n - 1;
     sort( r , wb , wa , ta , m );
     for( i = 0 ; i < tbc ; ++i ) wv[wb[i]=G(san[i])]=i;
     for( i = 0 ,j=0 , p=0 ; i<ta && j < tbc ; ++p )
     pos[ p ] =c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
     for( ; i < ta ; ++p ) pos[ p ] = wa[ i++ ];
     for( ; j < tbc ; ++p ) pos[ p ] = wb[ j++ ];
     return;
}

void getLCP( int r[], int pos[], int n, int rank[], int LCP[])
{
     int i , j , k = 0 ;
     for( i = 1 ; i <= n ;++i) rank[ pos[ i ] ] = i;
     for( i = 0 ; i < n ; LCP[ rank[ i++ ] ] = k )
     for( k ? k--:0, j = pos[rank[i]-1]; r[i+k]==r[j+k] ; ++k );
     return;
}

// sa[i]  i [1..n] (0..n-1)
// rank[i] i [0..n-1]
// height[i] i [1..n]
void get_suffix(char s[], int rank[], int pos[], int LCP[])
{
	int n = strlen( s );
	for( int i = 0 ; i <= n ; ++i ) r[ i ] = s[ i ];
	dc3( r , pos, n + 1 , 256);
    getLCP( r, pos , n , rank , LCP );
}
char str[ MAXN];
int main(){
    int t;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s",str) ){
        int len = strlen( str ) , i , lrs = 0;
        Clear( rank );Clear( pos ); Clear( LCP );
        get_suffix( str , rank, pos , LCP );

        for( i = 1 ; i <= len ; ++i ) lrs = max( lrs , LCP[ i ] );
        printf("%d\n" , lrs );
    }
    return 0;
}
