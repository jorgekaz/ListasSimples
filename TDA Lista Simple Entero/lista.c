#include "lista.h"

nodo * inicLista(){
    return NULL;
}

nodo * crearNodo(int dato){
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista){
    nodo * seg = lista;
    if(seg != NULL){

        while(seg->siguiente != NULL){
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodo * buscarNodo(int dato, nodo * lista){
    nodo * seg;
    seg = lista;

    while ((seg != NULL) && (seg->dato!=dato)){
        seg=seg->siguiente;
    }

    return seg;
}

nodo * agregarFinal(nodo* lista, nodo * nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * borrarNodoBuscado(int dato, nodo * lista){
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (lista->dato==dato)){
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while((seg != NULL) && (seg->dato!=dato)){
            ante = seg;
            seg = seg->siguiente;
        }

        if(seg!=NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }
    else{
        if(nuevoNodo->dato < lista->dato){
        lista = agregarPpio(lista, nuevoNodo);
        }else{
            nodo * ante = lista;
            nodo * seg = lista;
            while(seg != NULL && nuevoNodo->dato > seg->dato){
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista){
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

int verPrimero(nodo * lista){
    int rta;
    if(lista){
        rta=lista->dato;
    }
    return rta;

}

nodo * borrarPrimerNodo(nodo * lista){
    nodo * aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

nodo * borrarUltimoNodo(nodo * lista){
    nodo * aux;
    nodo * ante;
    if(lista!=NULL){
        if(lista->siguiente==NULL){
            aux=lista;
            lista=lista->siguiente;
            free(aux);
        }else{
            aux=lista;
            while(aux->siguiente!=NULL){
                ante=aux;
                aux=aux->siguiente;
            }
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}

int sumarEdadesLista(nodo * lista){
    int suma = 0;
    nodo * seg = lista;
    while (seg != NULL){
        suma = suma + seg->dato;
        seg = seg->siguiente;
    }
    return suma;
}

void mostrarNodo(nodo * aux){
    printf("%d ",aux->dato);
}

void recorrerYmostrar(nodo * lista){
    nodo * aux=lista;
    while(aux!=NULL){
        mostrarNodo(aux);
        aux=aux->siguiente;
    }
}

nodo * IngresarDatosAlFinal(nodo * lista){
    int dato;
    int cant;
    nodo * aux;
    printf(" INGRESE LA CANTIDAD A INGRESAR: ");
    scanf("%d",&cant);
    while(cant>0){
        printf(" INGRESE UN DATO: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarFinal(lista,aux);
        cant--;
    }
    return lista;
}

nodo * IngresarDatosAlPpio(nodo * lista){
    int dato;
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0){
        printf("ingrese un dato: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarPpio(lista,aux);
        cant--;
    }
    return lista;
}

nodo * AgregarUnNodoEnOrden(nodo * lista){
    int dato;
    nodo * aux=lista;
    printf(" INGRESE UN DATO: ");
    scanf("%d",&dato);
    aux=agregarEnOrden(lista,crearNodo(dato));
    return aux;
}

nodo * CrearListaOrdenada(nodo * lista){
    int cant;
    nodo * aux=lista;
    printf(" INGRESE CANTIDAD A INGRESAR: ");
    scanf("%d",&cant);
    while(cant>0){
        aux=AgregarUnNodoEnOrden(aux);
        cant--;
    }
    return aux;
}

void BusquedaDeUnNodo(nodo * lista){
    int dato;
    printf(" INGRESE DATO A BUSCAR: ");
    scanf("%d",&dato);
    nodo * aux=inicLista();
    aux=buscarNodo(dato,lista);
    if(aux!=NULL)
        printf("%d",aux->dato);
}

nodo * BorrarNodo(nodo * lista){
    int dato;
    printf(" INGRESE DATO A BORRAR DE LA LISTA: ");
    scanf("%d",&dato);
    lista=borrarNodoBuscado(dato,lista);
    return lista;
}

nodo * SubprogramaIngresarNuevoDato(){
    int dato;
    nodo * nuevoNodo;
    printf("\nINGRESE UN NUMERO:");
    scanf("%d", &dato);
    nuevoNodo = crearNodo(dato);
    return nuevoNodo;
}
