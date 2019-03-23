/*****************************************
 ***Problema: Is this the easiest problem
 ***ID: 11479
 ***Juez: UVA
 ***Tipo: Ad hoc, Triangles
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

    int t;
    long long A ,B , C;
    scanf("%d",&t);
    for(int i = 1 ; i <= t ; ++i){
        scanf("%lld %lld %lld",&A ,&B, &C);
        printf("Case %d: ",i);
        if( A < B + C && B < A + C && C < A + B){
            if(A == B && B == C )printf("Equilateral\n");
            else if( (A == B && A != C) || (A == C && A!= B) ||  (B==C  && B!= A) )printf("Isosceles\n");
            else if(A != C && B != A && C != B )printf("Scalene\n");
        }
        else printf("Invalid\n");
    }

    return 0;
}
