/*****************************************
 ***Problema: A Multiplication Game
 ***ID: 847
 ***Juez: UVA
 ***Tipo: Number Theory
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
   int n;
   while(cin>>n){
       bool stan=true;
       int p=1,last=1;
       while(1){
           if(stan){p*=9;last=1;stan=false;}
           else {p*=2;stan=true;last=2;}
           if(n<=p)break;
       }
       if(last==1)cout<<"Stan wins."<<endl;
       else cout<<"Ollie wins."<<endl;
   }
}
