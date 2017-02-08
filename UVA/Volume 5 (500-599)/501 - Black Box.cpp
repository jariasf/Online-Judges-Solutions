/*****************************************
 ***Problema: Black Box
 ***ID: 501
 ***Juez: UVA
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define MAX 30005
int a[ MAX ] , u[ MAX ];
int main(){
    int t , n , m;
    scanf("%d" , &t );
    for( int q = 0 ; q < t && scanf("%d %d" , &m , &n ) ; ++q ){
        if( q )
            printf("\n");
        for( int i = 0 ; i < m && scanf("%d" , &a[i]); ++i );
        for( int i = 0 ; i < n && scanf("%d" , &u[i]); ++i );
        multiset<int> ms;
        multiset<int>::iterator it;

        for( int i = 0 , j = 0 ; i < m && j < n ; ++i ){
            bool checked = false;
            if( ms.size() >= 1 && it == ms.end() ){
                it--;
                ms.insert(a[i]);
                if( *it <= a[i] ){
                    it++;
                }else
                    checked = true;
            }else{
                ms.insert( a[i] );
            }

            if( !checked && ms.size() > 1 && *it > a[i] )
                it--;

            if( ms.size() == 1 )
                it = ms.begin();

            while( j < n && u[j] == ms.size() ){
                printf("%d\n" , *(it));
                j++;
                it++;
            }
        }
    }

    return 0;
}
