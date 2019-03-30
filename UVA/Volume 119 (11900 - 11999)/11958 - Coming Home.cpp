/*****************************************
 ***Problema: Coming Home
 ***ID: 11958
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int main(){
    int t, K, hh , mm, val, mini, m;
    char time[ 6 ];
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d %s" , &K , &time );
        sscanf( time , "%d:%d" , &hh , &mm );
        mm += hh * 60;
        mini = 1<<30;
        for( int i = 0 ; i < K ; ++i ){
            scanf("%s %d" , &time , &val );
            sscanf( time , "%d:%d" , &hh , &m );
            m += hh * 60;
            if( m < mm ){
                m = 24*60 - mm + m;
                if( m + val < mini ) mini = m + val;
            }
            else{
                if( ( m + val - mm ) < mini ) mini = ( m + val - mm );
            }
        }
        printf("Case %d: %d\n" , q , mini);
    }

    return 0;
}
