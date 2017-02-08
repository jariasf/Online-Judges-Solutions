/*****************************************
 ***Problema: Network
 ***ID: 315
 ***Juez: UVA
 ***Tipo: Graph Theory, Articulation Point, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

///PUNTO ARTICULACION
///Si raiz tiene mas de un hijo es punto de articulacion
///Recuerde acerca de aristas de arbol(padre-hijo) y aristas de retroceso(antecesor-descendiente)
///low[k] posee el numero de dfs mas bajo a partir de un nodo, si se ve como arbol seria el mas alto

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;

#define MAXN 110
#define min(a,b) ( (a)<(b)?(a):(b) )

vector<int> ady[MAXN];
int n, cnt;
bool visitado[MAXN], flag[MAXN];
int  dfsNum[MAXN], low[MAXN];

void dfs(int k)
{
    ++cnt;
    dfsNum[k]=cnt,low[k]=cnt,visitado[k]= true;

    int hijos= 0;
    //adyacentes de la lista
    for( size_t i=0; i<ady[k].size(); ++i )
    {
        if(!visitado[ady[k][i]])
        {
            hijos++;
            dfs(ady[k][i]);
            low[k]=min(low[k],low[ady[k][i]]);

            //si no es raiz y el numero de dfs del adyacente(low) es igual al numeor de dfs del actual es punto de articulacion
            if( k!=1 && low[ady[k][i]]==dfsNum[k])flag[k]=true;
            //si es raiz y tiene mas de un hijo es puntoarticulacion
            if( k==1 && hijos>1 ) flag[k]=true;
        }
        else if(k!=ady[k][i]){

            ///el mas bajo sera el minimo entre el mas bajo actual y el numero de antecesor
            low[k]= min(low[k],dfsNum[ady[k][i]]);
        }
    }
}

void Init(){
    for( int i= 0; i<= MAXN; ++i )
       ady[i].clear();

    memset( visitado, false, sizeof(visitado) );
    memset( flag, false, sizeof(flag) );
    memset( dfsNum, 0, sizeof(flag) );
    memset( low, 0, sizeof(low) );
}

int main(void)
{
    int x,y,n;
    while(scanf("%d",&n) && n!=0){

        Init();
        cin.get();

        while(1){
           string s;
           getline(cin,s);
           s+=" ";
           stringstream ss(s);
           ss>>x;
           if(x==0)break;
           while(ss>>y){
              ady[x].push_back(y);
              ady[y].push_back(x);

           }
        }

        cnt=0;
        dfs(1);
        int num= 0;
        for( int i= 1; i<= n; ++i )
            if( flag[i] ){ num++;}

        printf("%d\n", num );
    }
    return 0;
}

