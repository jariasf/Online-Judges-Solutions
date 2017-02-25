/*****************************************
 ***Problema: Hardwood Species
 ***ID: 10226
 ***Juez: UVA
 ***Tipo: Data Structure, Trie
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(){
    int t,tot;
    scanf("%d",&t);
    char line[40];
    gets(line);
    gets(line);
    map<string,int>::iterator it;
    for(int q = 0; q<t; q++){
        if(q)putchar('\n');

        map<string,int> mp;

        tot=0;

        while(gets(line)){
            if(strcmp(line,"") == 0)break;
            mp[string(line)]++;
            ++tot;
        }

        for(it = mp.begin();it!= mp.end(); it++){
            printf("%s %.4lf\n",(*it).first.c_str(),((*it).second/(double)tot)*100.0);

        }
    }
    return 0;
}
