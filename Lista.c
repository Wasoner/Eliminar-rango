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
        n = n -> prox;
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