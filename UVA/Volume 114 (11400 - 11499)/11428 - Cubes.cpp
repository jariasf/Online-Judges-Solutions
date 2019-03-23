/*****************************************
 ***Problema: Cubes
 ***ID: 11428
 ***Juez: UVA
 ***Tipo: Brute Force
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


#define MAX 10001
int main(){
    int n , i ,j;
    long long p1,p2;
    bool b;

    while( scanf("%d", &n) && n){
        b = false;
        i = 0;

        for( ; i < 60; ++i){
           for( j = i+1 ; j < 60 ; ++j){
              p1 = j*j*j;p2 = i*i*i;
              if(p1 - p2 == n){
                 b =true;
                 break;
              }
           }
           if(b)break;
        }
        if(b)printf("%d %d\n",j,i);
        else printf("No solution\n");
    }

    return 0;
}
