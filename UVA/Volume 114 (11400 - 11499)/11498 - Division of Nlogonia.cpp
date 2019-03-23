/*****************************************
 ***Problema: Division of Nlogonia
 ***ID: 11498
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int k , x , y , x2, y2;

    while( scanf( "%d" , &k) && k){
        scanf( "%d %d", &x, &y );

        while( k-- ){
           scanf( "%d %d" ,&x2 , &y2 );

           if( y2 == y || x2 == x)printf("divisa\n");
           else if( x2 < x && y2 < y)printf("SO\n");
           else if( x2 > x && y2 > y )printf("NE\n");
           else if( x2 > x && y2 < y )printf("SE\n");
           else if( x2 < x && y2 > y) printf("NO\n");

        }
    }


    return 0;
}
