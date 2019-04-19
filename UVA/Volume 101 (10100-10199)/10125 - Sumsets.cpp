/*****************************************
 ***Problema: Sumsets
 ***ID: 10125
 ***Juez: UVA
 ***Tipo: Meet-in-the-middle
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
#define MAX 1005
int a[ MAX ] , len;

struct Data{
    int dif , i , j;
    Data( int d , int ii , int jj ) : dif( d ) , i(ii) , j(jj){}
    Data(){}
};
bool cmp2( Data d1 , Data d2 ){
    return d1.dif < d2.dif;
}

bool cmp(Data d1 , int val ){
    return d1.dif < val;
}

int main(){
    vector<Data> A;
    vector<int> B;
    while( scanf("%d" , &len ) , len ){
        for( int i = 0 ; i < len && scanf("%d" , &a[i ] ) ; ++i );
        for( int i = 0 ; i < len ; ++i ){
            for( int j = i + 1 ; j < len ; ++j ){
                A.push_back( Data(a[i] + a[j] , i , j) );
            }
        }

        int maxi = -1<<30;
        int d = -1;
        sort( A.begin() , A.end() , cmp2 );
        for( int i = 0 ; i < A.size() ; ++i ){
            B.push_back( A[i].dif );
        }
        for( int i = 0 ; i < len ; ++i ){
            for( int j = 0 ; j < len ; ++j ){
                if( i != j ){
                    int dif = a[i] - a[j];
                    int low = lower_bound( B.begin() , B.end() , dif ) - B.begin();
                    int up = upper_bound( B.begin() , B.end() , dif ) - B.begin();
                    while( low != A.size() && low >= 0 && low <= up && B[ low ] == dif ){
                        if( A[low].i != i && A[low].i != j && A[low].j != i && A[low].j != j ){
                            maxi = max( maxi , a[i] );
                            break;
                        }
                        low++;
                    }
                }
            }
        }

        if( maxi != -1<<30 ){
            printf("%d\n" , maxi );
        }else
            printf("no solution\n");
        A.clear();
        B.clear();
    }
    return 0;
}
