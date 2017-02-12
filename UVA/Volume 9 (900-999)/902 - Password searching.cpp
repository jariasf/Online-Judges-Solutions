/*****************************************
 ***Problema: Password search
 ***ID: 902
 ***Juez: UVA
 ***Tipo: Ad hoc, string, suffix array , KMP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    string ss;
    while (cin >> N >> ss){
      map<string,int> times;
      int best = 0;
      string ans;
      for (int i=0; i<=ss.size()-N; i++){
          string s = ss.substr(i, N);
          int tt = ++times[ s ];
          if ( tt > best ){
              best = tt;
              ans = s;
          }
      }
      cout << ans << endl;
    }
}
