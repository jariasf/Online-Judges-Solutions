/*****************************************************
 ***Problema: The Department of Redundancy Department
 ***ID: 484
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

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
#include <unordered_map>
using namespace std;

int main(){
    string line;
    int val;
    unordered_map<int,int> _hash;
    _hash.clear();
    vector<int> order;
    while( cin>>val ){
        if( _hash.find( val ) == _hash.end() ){
            order.push_back(val);
        }
        _hash[val]++;
    }

    for( int i = 0 ; i < order.size() ; ++i )
        printf("%d %d\n", order[i], _hash[order[i]]);
    return 0;
}
