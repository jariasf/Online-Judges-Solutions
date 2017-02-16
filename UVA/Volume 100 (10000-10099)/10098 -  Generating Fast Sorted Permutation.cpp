/***********************************************
 ***Problema: Generating Fast Sorted Permutation
 ***ID: 10098
 ***Juez: UVA
 ***Tipo: Ad hoc, next_permutation
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

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

    int t;
    scanf("%d", &t );
    char ss[ 20 ];
    for( int i = 0 ; i < t ; ++i ){
        scanf("%s" , ss );
        string s(ss);
        sort( s.begin() , s.end() );
        do{
            printf("%s\n", s.c_str());
        }while( next_permutation( s.begin() , s.end() ) );
        printf("\n");
    }

    return 0;
}
