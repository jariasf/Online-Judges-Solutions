/*****************************************
 ***Problema: Self Numbers
 ***ID: 640
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 1000000
bool a[MAX + 1];

int main(){
    
    memset( a, true, sizeof(a) );
    for(int i = 1; i <= MAX; i++){
        int sum = 0, n = i;
        while(n != 0){
            sum += n % 10;
            n = n / 10;
        }
        sum += i;
        if(sum <= MAX)
            a[sum] = false;
    }
    for(int i = 1; i <= MAX; i++)
        if(a[i])
            cout << i << endl;

    return 0;
}
