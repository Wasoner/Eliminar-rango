#include <stdio.h>

#include <stdlib.h>
//#include "elim-rango.h"




typedef struct nodo {
  int x;             // un elemento del conjunto
  struct nodo *prox; // proximo nodo de la lista enlazada
} Nodo;


void eliminarRango(Nodo **phead, double y, double z) {

    //Creacion de flag del nodo principal en falso 
    int f_NodoPrincipal = 0;
    //Creacion de flag de rango en falso 
    int f_Rango = 0;
    //Creacion de NodoAnterior
    Nodo *nodoAnterior = NULL;
    //Recorrer la lista enlazada

    Nodo *n = *phead;

    while (n != NULL ) {

        printf("%d\n", n ->x);
        if ( n -> x >=y && n->x <= z) {

            printf("Cumplio la condicion con: %d\n", n-> x);

            f_Rango = 1;
            Nodo *nodoSiguiente = n -> prox ; 
            //printf("EL nodo sgte es: %d\n", nodoSiguiente ->x);
            if (nodoSiguiente != NULL && nodoAnterior != NULL){
                printf("Primer if\n");
                //Enlazar el nodo anterior al nodo siguiente
                nodoAnterior->prox = nodoSiguiente;
                printf("EL nodo anterior prox es: %d\n",nodoAnterior->x );
                
            } else if (nodoSiguiente == NULL && nodoAnterior != NULL) {
                
                nodoAnterior->prox = NULL;
            }
            //n->prox = NULL;
            free(n);
            n = nodoSiguiente;
            
            
        } else{

            printf("NO Cumplio la condicion con: %d\n", n-> x);
            if (f_NodoPrincipal == 0){
                *phead = n;
                f_NodoPrincipal = 1;
            }else if (f_Rango == 1)
            {
                break;
            }
            nodoAnterior = n;
            printf("EL nodo anterior es: %d\n",nodoAnterior->x );
            n = n->prox;
            //printf("EL proximo n es: %d\n", n ->x);

        }
    }

    
    if (f_NodoPrincipal == 0)
    {
      *phead = NULL;
    }
    

  

}

int main(){
    Nodo* n1 = NULL;
    n1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n2 = NULL;
    n2 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n3 = NULL;
    n3 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n4 = NULL;
    n4 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* n5 = NULL;
    n5 = (Nodo*)malloc(sizeof(Nodo));

    n1 ->x = 9;
    n1->prox = NULL;
    n2 ->x = 8;
    n2->prox = n1; 
    n3 ->x = 7;
    n3->prox = n2;
    n4 ->x = 4;
    n4->prox = n3;
    n5 ->x = 2;
    n5->prox = n4;    
  
  

    Nodo *heap = n5;
    eliminarRango(&heap, 0 , 9);
    while (heap != NULL)
    {
        printf("%d", heap->x);
        heap = heap->prox;
    }
    

    return 0;

}