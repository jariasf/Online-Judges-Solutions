/*****************************************
 ***Problema: Pseudo-Random Numbers
 ***ID: 350
 ***Juez: UVA
 ***Tipo: Cycle Finding
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>


int Z, I , M, L;

int f( int L ){
    return ( Z * L + I ) % M;
}

void TortoiseHare(int x)
{
    int s = 0, p = 1;

    // i es la tortuga, para iniciar el siguiente paso, j es el conejo, hasta el punto de partida para los dos pasos siguientes.
    int i = f(x), j = f(f(x));

    // Velocidad de una tortuga, conejo de velocidad doble. Trate de encontrar un ciclo de azar.
    while (i != j) i = f(i), j = f(f(j));

    // Tortugas hasta el punto de partida en el conejo a la tortuga original.
    j = i; i = x;

    // La tortuga y la liebre son uno de velocidad. Comience a buscar bucle punto de partida.
    while (i != j) i = f(i), j = f(j), s++;

    // Los conejos de las tortugas el siguiente paso.
    j = f(i);

    // Tortuga no se mueve, una velocidad de conejo. Comience a buscar por el período mínimo.
    while (i != j) j = f(j), p++;

    printf("%d\n",p);
}

int main(){
    int t = 1;
    while( scanf("%d %d %d %d", &Z, &I, &M, &L) && (Z + I + M + L ) ){
         printf("Case %d: ", t++ );
         TortoiseHare( L );
    }

    return 0;
}
