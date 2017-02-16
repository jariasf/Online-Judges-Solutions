/*****************************************
 ***Problema: Reverse and Add
 ***ID: 10018
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *****************************************/
//old code
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


bool isPal(string c){
    int l=c.length();
    for(int i=0,j=l-1;i<=l/2 && j>=l/2;i++,j--){
        if(c[i]!=c[j])return false;
    }
    return true;
}

long long toLong(string s){
    stringstream ss(s);
    long long n;
    ss>>n;
    return n;
}

string toStr(long long n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}

int main(){
    int casos,it,i;
    cin>>casos;
    string n,nr;
    while(casos--){
        cin>>n;
        i=0;
        while(i<1005){
            nr=n;
            reverse(nr.begin(),nr.end());
            n=toStr(toLong(n)+toLong(nr));
            i++;
            if(isPal(n)){
                cout<<i<<" "<<n<<endl;
                break;
            }

        }
    }

    return 0;
}
