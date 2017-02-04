/*****************************************
 ***Problema: Testing the CATCHER
 ***ID: 231
 ***Juez: UVA
 ***Tipo: DP, LIS
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
#define N 100002
int B[N], f[N], a[N];
int n,t;
void LIS() {
	int i, mid, right, left, num, blen, max = 0;

	blen = 1;
	B[0] = a[0];
	for (i = 0; i < n; i++) {
		num = a[i], left = 0, right = blen;
		while (left <= right) {
			mid = (left + right) / 2;
			if (B[mid] < num) left = mid + 1;
			else right = mid - 1;
		}
		f[i] = left;
		B[left] = num;

		if (blen < left) blen = left;
		if (max < f[i]) max = f[i];
	}
	printf("Test #%d:\n",t++);
	printf("  maximum possible interceptions: %d\n", max);
}

int main() {
    int x;
    t=1;
	while (scanf("%d", &x) && x!=-1){
        if(t-1)printf("\n");
        n=0;
        a[n++]=x;
        while(scanf("%d",&x) && x!=-1){
		   a[n++]=x;
        }

        reverse(a,a+n);
		LIS();
	}
	return 0;
}
