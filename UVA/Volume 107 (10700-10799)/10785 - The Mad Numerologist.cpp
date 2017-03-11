/*****************************************
 ***Problema: The Mad Numerologist
 ***ID: 10785
 ***Juez: UVA
 ***Tipo: Greedy
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

char vowel[ 6 ] = "AUEOI";
char consonant[ 26 ] = "JSBKTCLDMVNWFXGPYHQZR";

int main(){
    int t , n , idxVowel , idxConsonant , countConsonant , countVowel , lenVowel ,lenConsonant;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        printf("Case %d: " , q );
        countVowel = countConsonant = 0;
        idxVowel = idxConsonant = 0;
        string V = "" , C = "";
        for( int i = 1 ; i <= n ; ++i ){
            if( i & 1 ){
                V += vowel[ idxVowel ];
                countVowel++;
                if( countVowel >= 21 ){
                    countVowel = 0;
                    idxVowel = ( idxVowel + 1 ) % 5;
                }
            }
            else{
                C += consonant[ idxConsonant ];
                countConsonant++;
                if( countConsonant >= 5 ){
                    countConsonant = 0;
                    idxConsonant = ( idxConsonant + 1 ) % 21;
                }
            }
        }
        sort( V.begin() , V.end() );
        sort( C.begin() , C.end() );
        lenVowel = lenConsonant = 0;
        for( int i = 1 ; i <= n ; ++i ){
            if( i & 1 ){
                printf("%c" , V[ lenVowel++ ] );
            }
            else printf("%c" , C[ lenConsonant++ ] );
        }
        puts("");
    }
    return 0;
}
