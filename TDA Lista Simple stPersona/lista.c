#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include  <string.h>

nodo *inicLista(){
    return NULL;
}

nodo * crearNodo (stPersona dato){
    nodo *aux =(nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux-> siguiente = NULL;
    return aux;
}

nodo *agregarPpio(nodo * lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista=nuevoNodo;
    }else{
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}

nodo *buscarUltimo(nodo *lista){
    nodo *seg=lista;
    if(seg!=NULL){
        while(seg->siguiente!=NULL){
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodo *buscarNodo(int edad, nodo *lista){
    nodo *aux=lista;
    if(aux->siguiente!=NULL){
        while((aux->siguiente!=NULL)&&(aux->dato.edad=!edad)){
            aux=aux->siguiente;
        }
    }
    return aux;
}

nodo *agregarFinal(nodo *lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista=nuevoNodo;
    }else{
        nodo * ultimo= buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}

nodo *borrarNodo(char nombre[20], nodo *lista){
    nodo *seg=lista;
    nodo *ante=NULL;
    if(lista!=NULL&&(strcmp(seg->dato.nombre,nombre)==0)){
        nodo *seg=lista;
        lista=lista->siguiente;
        free(seg);
    }if(seg!=NULL){
        while(seg!=NULL&&(strcmp(seg->dato.nombre,nombre)!=0)){
            ante=seg;
            seg=seg->siguiente;
        }if(seg!=NULL){
            ante->siguiente=seg->siguiente; // analizar y corregir
            free(seg);
        }
    }
    return lista;
}

nodo *agregarEnOrden(nodo *lista, nodo *nodoNuevo){
    if(lista==NULL){
        lista=nodoNuevo;
    }
    else{
        if(nodoNuevo->dato.edad<lista->dato.edad){
            lista=agregarPpio(lista,nodoNuevo);
        }
        else{
            nodo *seg=lista;
            nodo *ante=NULL;
            while(seg!=NULL&&seg->dato.edad<nodoNuevo->dato.edad){
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg!=NULL){
                ante->siguiente=nodoNuevo;
                nodoNuevo->siguiente=seg;
            }
        }
    }
    return lista;
}

nodo *borrarTodaLaLista(nodo *lista){
    nodo * seg=NULL;
    while(lista!=NULL){
        seg=lista;
        lista=lista->siguiente;
        free(seg);
    }
    return lista;
}

void mostrarLista(nodo *lista){
    nodo *seg=lista;
    while(seg!=NULL){
        mostraNodo(seg->dato);
        seg=seg->siguiente;
    }
}

void mostraNodo(stPersona dato){
    puts("*------------------------*");
    printf("Edad: %d\n",dato.edad);
    printf("Nombre: %s\n",dato.nombre);
    puts("*------------------------*");
}

nodo * eliminarPrimero(nodo *lista){
    if(lista!=NULL){
        nodo *aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    return lista;
}

nodo *eliminarUltimo(nodo *lista){
    nodo *aBorrar;
    if (lista!=NULL){
        if(lista->siguiente==NULL){
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
    }else{
        nodo *seg, *ante;
        seg=lista;
        while(seg->siguiente!=NULL){
            ante=seg;
            seg=seg->siguiente;
        }
        ante->siguiente=NULL;
        free(seg);
    }
    return lista;
}
