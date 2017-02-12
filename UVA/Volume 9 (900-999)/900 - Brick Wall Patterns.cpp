/*****************************************
 ***Problema: Brick Wall Patterns
 ***ID: 900
 ***Juez: UVA
 ***Tipo: Fibonacci Numbers, math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
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

    int n;
    long long dp[51];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=50;i++){
       dp[i]=dp[i-1]+dp[i-2];
    }
    while(scanf("%d",&n) && n){
        printf("%lld\n",dp[n]);

    }
    return 0;
}
