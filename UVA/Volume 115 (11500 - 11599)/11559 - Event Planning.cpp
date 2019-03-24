/*****************************************
 ***Problema: Event Planning
 ***ID: 11559
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
    int N , B , H ,W , mini, price, bed;
    while( scanf("%d %d %d %d" , &N , &B , &H , &W ) == 4 ){
        mini = 1<<30;
        while( H-- ){
            scanf("%d" , &price );
            for( int i = 0 ; i < W ; ++i ){
                scanf("%d" , &bed );
                if( bed >= N && price * N <= B ){
                    if( mini > price * N ) mini = price * N;
                }
            }
        }
        if( mini == 1<<30 )printf("stay home\n");
        else printf("%d\n" , mini );
    }

    return 0;
}
