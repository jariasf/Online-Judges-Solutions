/*****************************************
 ***Problema: Updating a Dictionary
 ***ID: 12504
 ***Juez: UVA
 ***Tipo: Strings
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define psi pair< string , string >
#define mp make_pair
vector< psi > parse( string s ){
    int i;
    string key , val;
    stringstream ss( s + " " );
    vector<psi> v;
    while( ss>>s ){
        for( i = 0 ; s[ i ] ; ++i ) if( s[ i ] == ':' ) s[ i ] = ' ';
        stringstream ss2( s + " " );
        ss2>>key>>val;
        v.push_back( mp( key , val ) );
    }
    return v;
}

int main(){
    int t , l1 , l2 , i , j;
    scanf("%d" , &t );
    string d1 ,d2;
    getline( cin , d1 );
    while( t-- > 0 ){
        getline( cin , d1 );
        getline( cin , d2 );
        l1 = d1.size(); l2 = d2.size();
        for( i = 0 ; i < l1 ; ++i )
            if( d1[ i ] == '{' || d1[ i ] == ',' || d1[ i ] == '}' ) d1[ i ] = ' ';

        for( i = 0 ; i < l2 ; ++i )
            if( d2[ i ] == '{' || d2[ i ] == ',' || d2[ i ] == '}' ) d2[ i ] = ' ';

        vector< psi > v1 , v2;

        v1 = parse( d1 );
        v2 = parse( d2 );
        sort( v1.begin() , v1.end() );
        sort( v2.begin() , v2.end() );

        vector< string > change_value , new_key , removed_key;
        for( i = 0 ; i < v2.size() ; ++i ){
            bool exist = false;
            for( j = 0 ; j < v1.size() ; ++j ){
                if( v1[ j ].first == v2[ i ].first ){
                    exist = true;
                    if( v1[ j ].second != v2[ i ].second ){
                        change_value.push_back( v2[ i ].first );
                    }
                    break;
                }
            }
            if( !exist ) new_key.push_back( v2[ i ].first );
        }

        for( i = 0 ; i < v1.size() ; ++i ){
            bool exist = false;
            for( j = 0 ; j < v2.size() ; ++j ){
                if( v1[ i ].first == v2[ j ].first ){
                    exist = true;
                    break;
                }
            }
            if( !exist ) removed_key.push_back( v1[ i ].first );
        }
        if( !new_key.size() && !change_value.size() && ! removed_key.size() ){
            puts("No changes");
            puts("");
            continue;
        }
        if( new_key.size() > 0 ){
            printf("+%s" , new_key[ 0 ].c_str() );
            for( i = 1 ; i < new_key.size() ; ++i ){
                printf(",%s" , new_key[ i ].c_str() );
            }
            printf("\n");
        }
        if( removed_key.size() > 0 ){
            printf("-%s" , removed_key[ 0 ].c_str() );
            for( i = 1 ; i < removed_key.size() ; ++i ){
                printf(",%s" , removed_key[ i ].c_str() );
            }
            printf("\n");
        }

        if( change_value.size() > 0 ){
            printf("*%s" , change_value[ 0 ].c_str() );
            for( i = 1 ; i < change_value.size() ; ++i ){
                printf(",%s" , change_value[ i ].c_str() );
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
