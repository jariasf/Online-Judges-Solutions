/*****************************************
 ***Problema: Roman Numerals
 ***ID: 11616
 ***Juez: UVA
 ***Tipo: Ad hoc, conversion
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

int romanToDecimal(char *s) {
    static int val[256]={-1};
    if (val[0] < 0) {
        int a[] = {1, 5, 10, 50, 100, 500, 1000 };
        for (int i = 0; i < 256; i++) val[i] = 0;
        for (int i = 0; i < 7; i++) val["IVXLCDM"[i]] = a[i];
    }

    int res = 0;
    for (; *s; s++) {
        res += val[*s];
        for (char *t = s+1; *t; t++) {
            if (val[*t] > val[*s]) {
                res -= 2*val[*s];
                break;
            }
        }
    }
    return res;
}

#define MAX 4000
int main(){

    char c[MAX];

    while(scanf("%s",&c) != EOF){
        //decimal a romano
        if(isdigit(c[0])){
            int n = atoi(c);
            for (;n >= 1000 && n; n -= 1000)
                printf("M");
            if (n / 100 == 9) printf("CM"), n -= 900;
            for (;n >= 500 && n; n -= 500)
                printf("D");
            if (n / 100 == 4) printf("CD"), n -= 400;
            for (;n >= 100 && n; n -= 100)
                printf("C");
            if (n / 10 == 9) printf("XC"), n -= 90;
            for (;n >= 50 && n; n -= 50)
                printf("L");
            if (n / 10 == 4) printf("XL"), n -= 40;
            for (;n >= 10 && n; n -= 10)
                printf("X");
            if (n == 9) printf("IX"), n -= 9;
            for (;n >= 5 && n; n -= 5)
                printf("V");
            if (n == 4) printf("IV"), n -= 4;
            for (;n >= 1 && n; n -= 1)
                printf("I");
            printf("\n");
        }
        //romano a decimal
        else{
           printf("%d\n",romanToDecimal(c));
        }
    }

    return 0;
}
