/*****************************************
 ***Problema: What is the Median
 ***ID: 10107
 ***Juez: UVA
 ***Tipo: Sorting, mediam selection
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
#define MAX 10005
int main(){
    int n, l = 0;
    long long num;
    vector<long long> a;
    vector<long long >::iterator low;
    while( cin>>num ){
        low=lower_bound ( a.begin() , a.end(), num);
        a.insert( low, num );
        l = a.size();
        if( l & 1 )cout<<a[ l/2 ]<<endl;
        else cout<<( a[ l/2 ] + a[ l/2 - 1] )/2<<endl;
    }
    return 0;
}
