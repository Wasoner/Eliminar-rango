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

            f_Rango = 1;
            Nodo *nodoSiguiente = n -> prox ; 
            if (nodoSiguiente != NULL && nodoAnterior != NULL){

                //Enlazar el nodo anterior al nodo siguiente
                nodoAnterior->prox = nodoSiguiente;
                
            } else if (nodoSiguiente == NULL && nodoAnterior != NULL) {
                
                nodoAnterior->prox = NULL;
            }

            free(n);
            n = nodoSiguiente;
            
            



        }
    }
    

  

}

int main(){

    Nodo n1 = {9, NULL};
    Nodo n2 = {8, &n1};
    Nodo n3 = {7, &n2};
    Nodo n4 = {4, &n3};
    Nodo n5 = {2, &n4};

    Nodo *heap = &n5;
    eliminarRango(&heap, 4 , 5);

    return 0;

}