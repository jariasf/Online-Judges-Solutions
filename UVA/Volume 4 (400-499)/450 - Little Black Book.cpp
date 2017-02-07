/*****************************************
 ***Problema: Little Black Book
 ***ID: 450
 ***Juez: UVA
 ***Tipo: Sorting
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

struct Book{
    string dep , title , fn , ln , hp , wp , cb , ha;
    Book(){}
} v[ 100005 ];

bool cmp( Book b1 , Book b2 ){
    return b1.ln < b2.ln;
}

int main(){
    int t , l , q = 0;
    char line[ 100005 ];
    scanf("%d" , &t );
    gets( line );
    char dep[ 100005 ];
    string s;
    for( int qq = 0 ; qq < t ; ++qq ){
        gets( dep );
        while( gets( line ) ){
            l = strlen( line );
            if( l == 0 )break;
            strcat( line , ",");
            l++;
            string ss[ 8 ];
            for( int i = 0 , j = 0 ; i < l ; ++i ){
                s = "";
                while( i < l && line[ i ] != ',' ){
                    s += line[ i ];
                    i++;
                }
                ss[ j++ ] = s;
            }
            v[ q ].title = ss[ 0 ];
            v[ q ].fn = ss[ 1 ];
            v[ q ].ln = ss[ 2 ];
            v[ q ].ha = ss[ 3 ];
            v[ q ].hp = ss[ 4 ];
            v[ q ].wp = ss[ 5 ];
            v[ q ].cb = ss[ 6 ];
            v[ q ].dep = string( dep );
            q++;
        }
    }

    sort( v , v + q , cmp );

    for( int i = 0 ; i < q ; ++i ){
        printf("----------------------------------------\n");
        printf("%s %s %s\n" , v[ i ].title.c_str() , v[ i ].fn.c_str() , v[ i ].ln.c_str() );
        printf("%s\nDepartment: %s\n" , v[ i ].ha.c_str() , v[ i ].dep.c_str() );
        printf("Home Phone: %s\nWork Phone: %s\nCampus Box: %s\n" , v[ i ].hp.c_str() , v[ i ].wp.c_str() , v[ i ].cb.c_str() );
    }

    return 0;
}
