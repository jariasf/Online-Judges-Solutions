/*****************************************
 ***Estructura de Datos: Treap
 ***Implementación: Mediante Split y Merge
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
Ejemplo de entrada
9
15 39
6 33
17 21
5 19
13 29
8 17
14 15
11 9
9 51
*/

#include <stdio.h>
#include <stdlib.h>
//Consideramos un max-Heap
struct Node{
    int key , priority;            //clave y prioridad de un nodo
    Node* left , *right;           //subarbol izquierdo y derecho
    Node( int k , int p ): key( k ) , priority( p ), left( NULL ) , right( NULL ){} //para test
    Node( int k ): key( k ) , left( NULL ) , right( NULL ) , priority( rand() ){}
};

//Busqueda de un nodo por su clave, cumple propiedades de BST
Node* search( Node *root , int key ){
    if( root == NULL ) return NULL;
    if( key < root -> key ) return search( root -> left , key );
    if( key > root -> key ) return search( root -> right , key );
    return root;
}

//Split: Ingresa la raíz del árbol, la clave del nodo a insertar y los subárboles izquierdo y derecho
void split( Node* root , int key , Node *&L , Node*&R ){
    if( root == NULL ){ L = R = NULL; return; }
    else if( root -> key < key ){ split( root ->right , key , root -> right , R ); L = root;}
    else{ split( root -> left , key , L , root -> left ); R = root; }
}

//Inserción: Recibo un arbol y el nodo a insertar
Node* insert( Node *root , Node *novo ){
    if( root == NULL ) return novo;
    if( root -> priority < novo -> priority ){ //si no cumple propiedad de heap en la ubicacion actual
          split( root , novo -> key , novo -> left , novo -> right );  //insertamos nodo mediante split
          return novo; //retorno nuevo nodo con sus respectivos subárboles izquierdo y derecho
    }
   //Búsqueda del elemento por la clave.
    if( root -> key < novo -> key ) root -> right = insert( root -> right , novo );
    else root -> left = insert( root -> left , novo );
    return root;
}

//Merge: Recibo un Arbol Izquierdo y un Arbol Derecho
//Todas las claves de L deben ser menores que R
Node* merge( Node* L , Node* R ){
    Node *root;			          //Este sera nuestro nuevo arbol
    if( L == NULL || R == NULL ) root = ( L != NULL ? L : R );
    else if( L -> priority < R -> priority ){ R -> left = merge( L , R -> left ); root = R; }
    else{ L -> right = merge( L -> right , R ); root = L; }
    return root;
}

//Eliminacion: Recibo un arbol y la clave del nodo a eliminar
Node* erase( Node* root , int key ){
    if( root == NULL ) return NULL;
    if( root -> key == key ){ //si lo encontre, mezclo sus subarboles
        Node *aux = merge( root -> left , root -> right );
        delete root; //elimino nodo actual
        return aux; //retorno nuevo arbol
    }
   //Busqueda de nodo por clave
    if( root -> key < key ) root -> right = erase( root -> right , key );
    else root -> left = erase( root -> left , key );
    return root;
}

//Limpiamos el arbol de prueba
Node* clear( Node* root ){
    if( root != NULL ){
        clear( root -> left );
        clear( root -> right );
        delete root;
    }
}

//Recorrido Preorder del Treap
void Traverse( Node *root ){
    if( root == NULL ) return;
    printf("[%d,%d]->" , root -> key , root -> priority );
    Traverse( root -> left );
    Traverse( root -> right );
}

int main(){
    Node* treap = NULL;
    int n , x ,c , p;
    printf("Ingrese el numero de elementos: ");
    scanf("%d" , &n );
    for( int i = 0 ; i < n ; ++i ){
        printf("Ingrese elemento y prioridad: "); //solo para testear, el treap real solo se ingresara la clave
        scanf("%d%d" , &x , &p );
        treap = insert( treap , new Node( x , p) );
    }
    Traverse( treap ); //recorrido preorder del arbol
    printf("\n");

    printf("Busquemos un elemento\n");
    while( scanf("%d" , &x ) == 1 ){
        Node* elem = search( treap , x );
        if( elem == NULL )puts("No encontramos el elemento ingresado");
        else{
            puts("Elemento encontrado desea borrarlo 1/0?"); //si deseamos borrar presionamos 1, sino presionamos 0
            scanf("%d" , &c );
            if( c )treap = erase( treap , x );
            Traverse( treap );  //muestro arbol luego de posibles eleminaciones
            printf("\n");
        }
    }
    clear( treap );
    return 0;
}
