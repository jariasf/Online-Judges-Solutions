/*****************************************
 ***Problema: Box of bricks
 ***ID: 591
 ***Juez: UVA
 ***Tipo: Ad hoc
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

using namespace std;

int main(){
    int n,hi,i,sum,prom,c=1,p,ne;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        int h[n];
        sum=0;p=0;ne=0;
        for(i=0;i<n;i++){
            scanf("%d",&hi);
            h[i]=hi;
            sum+=hi;
        }
        prom=sum/n;
        for(i=0;i<n;i++){
           if(h[i]-prom<0)ne+=(prom-h[i]);
           else p+=h[i]-prom;
        }
        printf("Set #%d\n",c++);
        printf("The minimum number of moves is %d.\n\n",std::max(p,ne));
    }

    return 0;
}
