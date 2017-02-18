/*****************************************
 ***Problema: CDVII
 ***ID: 10138
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
#define MAX 24
#define MAXN 10005
int a[ MAX ];
map<string , int> cost;
int len;

struct Data{
    string number , time, op;
    int km, month , day , hour , minute;
    void convert(){
        string t = "";
        for( int i = 0 ; i < time.length() ; ++i ){
            if( time[i] == ':' )
                t += " ";
            else
                t += time[i];
        }
        stringstream ss(t);
        ss>>month>>day>>hour>>minute;
    }
    Data(){}
}data[ MAXN ];

bool cmp( Data d1 , Data d2 ){
    return d1.number < d2.number || ( d1.number == d2.number && d1.time < d2.time );
}

int main(){
    int t;
    scanf("%d", &t );
    string line;
    for( int qq = 0 ; qq < t ; ++qq ){
        if( qq )
            printf("\n");
        for( int i = 0 ; i < 24 && scanf("%d" , &a[i]) ; ++i );

        len = 0; cost.clear();
        getline( cin , line );

        while( getline( cin , line ) && line.length() > 0 ){
            stringstream ss( line );
            Data d;
            ss>>d.number>>d.time>>d.op>>d.km;
            d.convert();
            data[ len++ ] = d;
        }

        sort( data , data + len  , cmp );
        for( int i = 0 ; i < len - 1 ; ++i ){
            Data d = data[ i ] , next = data[ i + 1 ];
            if( d.number == next.number && d.op == "enter" && next.op == "exit" ){
                int v1 = a[ d.hour ], v2 = a[ next.hour ];
                cost[ d.number ] += v1 * abs( next.km - d.km ) + 100;
            }
        }

        for( map<string , int> :: iterator it = cost.begin() ; it != cost.end() ; ++it ){
            printf("%s $%.2lf\n" , (it -> first).c_str() , (it -> second + 200)/100.0 );
        }
    }
    return 0;
}
