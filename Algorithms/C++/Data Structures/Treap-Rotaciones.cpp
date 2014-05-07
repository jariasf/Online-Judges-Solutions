/*****************************************
 ***Estructura de Datos: Treap
 ***Implementación: Mediante Rotaciones
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

//Rotación a la Derecha
Node* rotRight( Node *root ){       //Raiz es el argumento, se retornara pivot como raiz luego de rotar
    Node* pivot = root -> left;     //Asigno a pivot el subarbol izquierdo de root
    root -> left = pivot -> right;  //Puntero izquierdo de root apunta a derecho de pivot.
    pivot -> right = root;          //Puntero derecho de pivot apunta a root.
    return pivot;
}

//Rotación a la Izquierda
Node* rotLeft( Node *root ){        //Raiz es el argumento, se retornara pivot como raiz luego de rotar
    Node* pivot = root -> right;    //Asigno a pivot el subarbol derecho de root
    root -> right = pivot -> left;  //Puntero derecho de root apunta a derecho de pivot.
    pivot -> left = root;           //Puntero izquierdo de pivot apunta a root.
    return pivot;
}

//Inserción: Recibo un arbol y el nodo a insertar
Node* insert( Node *root , Node *novo ){       //Ingreso árbol actual y el nuevo nodo a insertar
    if( root == NULL ) return novo;            //Encontre posición para nodo
    if( root -> key < novo -> key ){           //Buscamos por la derecha
        root -> right = insert( root -> right , novo );
        if( root -> right -> priority > root -> priority ) root = rotLeft( root ); //rotacion izquierda
    }
    else{				                       //Buscamos por la izquierda
    //if( root -> key > novo -> key ){         //Para nodos no repetidos
        root -> left = insert( root -> left , novo );
        if( root -> left -> priority > root -> priority ) root = rotRight( root ); //rotacion derecha
    }
    return root;
}


//Eliminacion: Recibo un arbol y la clave del nodo a eliminar
Node* erase( Node* root , int key ){
    if( root == NULL ){ return root; }
    //Realizo la busqueda por clave
    if( root -> key < key ) root -> right = erase( root -> right , key );
    else if( root -> key > key ) root -> left = erase( root -> left , key );
    else{
        //Si tengo ambos hijos puedo comparar prioridades
        if( root -> left != NULL ){
            if( root -> right != NULL ){
                //Elijo el de mayor prioridad
                if( root -> left -> priority < root -> right -> priority ){
                    root = rotLeft( root );  //rotacion izquierda
                    root -> left = erase( root -> left , key );
                }else{
                    root = rotRight( root ); //rotacion derecha
                    root -> right = erase( root -> right , key );
                }
            }
            else{ //Si tengo solo hijo izquierdo basta con cambiar con dicho nodo y eliminar el actual
                Node* aux = root -> left;  delete root; return aux;
            }
        }
        else{
            //Si tengo solo hijo derecho basta con cambiar con dicho nodo y eliminar el actual
            if( root -> right != NULL ){
                Node* aux = root -> right;  delete root; return aux;
            }
            else{ //Si mi nodo actual es hoja lo elimino
                delete root;  return NULL;
            }
        }
    }
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
