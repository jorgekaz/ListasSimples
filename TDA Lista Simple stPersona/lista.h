#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct {
    char nombre[30];
    int edad;
}stPersona;

typedef struct{
    stPersona dato;
    struct nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stPersona dato);
nodo* agregarPpio(nodo* lista, nodo* nuevoNodo);
nodo* buscarUltimo(nodo* lista);
nodo* buscarNodo(int edad, nodo* lista);
nodo* agregarFinal(nodo *lista, nodo* nuevoNodo);
nodo* borrarNodo(char nombre[20], nodo *lista);
nodo* agregarEnOrden(nodo *lista, nodo *nodoNuevo);
nodo* borrarTodaLaLista(nodo *lista);
void mostrarLista(nodo *lista);
void mostraNodo(stPersona dato);
nodo* eliminarPrimero(nodo *lista);
nodo* eliminarUltimo(nodo *lista);

#endif // LISTA_H_INCLUDED
