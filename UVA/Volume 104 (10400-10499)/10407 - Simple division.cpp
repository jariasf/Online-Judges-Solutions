/*****************************************
 ***Problema: Simple Division
 ***ID: 10407
 ***Juez: UVA
 ***Tipo: Number Theory, GCD
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
#define MAX 1001
int main(){
    int n,i,min;
    int a[MAX]={0};
    while(scanf("%d",&n) && n){
        i=0;
        min=n;
        a[i++]=n;
        while(scanf("%d",&n) && n){
            a[i++]=n;
            min=std::min(min,n);
        }
        for(int j=0;j<i;j++)a[j]-=min;
        int q=a[0];
        for(int j=1;j<i;j++)q=__gcd(q,a[j]);

        printf("%d\n",q);
    }

    return 0;
}
