#include "ColoresLista.h"
#include "Color.h"


using namespace std;

void coloresLista_crearLista(ListaColores &lista, string nombre)
{
    ListaColores nuevaLista = new struct EstructuraListaColor;
    nuevaLista->color = crearColor(nombre);
    nuevaLista->siguiente = NULL;
    lista = nuevaLista;
}

void coloresLista_agregarAlInicio(ListaColores &lista, string nombre)
{
    if(lista == NULL)
    {
        coloresLista_crearLista(lista, nombre);
        return;
    }
    ListaColores nueva = new struct EstructuraListaColor;
    nueva->color = crearColor(nombre);
    nueva->siguiente = lista;
    lista = nueva;
}

void coloresLista_agregarAlFinal(ListaColores &lista, string nombre)
{
    if(lista == NULL)
    {
        coloresLista_crearLista(lista, nombre);
        return;
    }
    ListaColores actual = lista, nueva = new struct EstructuraListaColor;
    nueva->color = crearColor(nombre);
    nueva->siguiente = NULL;
    while(actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nueva;
}

void coloresLista_mostrarTodosLosElementos(ListaColores lista)
{
    while(lista != NULL)
    {
        cout << color_getNombre(lista->color) << endl;
        lista = lista->siguiente;
    }
}

Color coloresLista_obtenerColor(ListaColores &lista, int indice)
{
    int i = 1;
    ListaColores actual = lista;
    while(actual->siguiente != NULL && i < indice)
    {
        actual = actual->siguiente;
        i++;
    }
    if(i == indice)
    {
        return actual->color;
    }
    return NULL;
}

int coloresLista_indiceDelColor(ListaColores &lista, string nombre)
{
    int indice = 1;
    ListaColores actual = lista;
    while(actual != NULL)
    {
        if(color_getNombre(actual->color) == nombre)
        {
            return indice;
        }
        actual = actual->siguiente;
        indice++;
    }
    return 0;
}

int coloresLista_getTamanio(ListaColores lista)
{
    int tamanio = 0;
    while(lista != NULL)
    {
        lista = lista->siguiente;
        tamanio++;
    }
    return tamanio;
}

void coloresLista_agregarAlFinalSinRepetir(ListaColores &lista, string nombre)
{
    if(lista == NULL)
    {
        coloresLista_crearLista(lista, nombre);
        return;
    }
    ListaColores actual = lista, nueva = new struct EstructuraListaColor;
    ListaColores anterior;
    bool yaExiste = false;
    do
    {
        if(color_getNombre(actual->color) == nombre)
        {
            yaExiste = true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    while(actual != NULL);
    if(!yaExiste)
    {
        nueva->color = crearColor(nombre);
        nueva->siguiente = NULL;
        anterior->siguiente = nueva;
    }
}

void coloresLista_agregarAlInicioSinRepetir(ListaColores &lista, string nombre)
{
    if(lista == NULL)
    {
        coloresLista_crearLista(lista, nombre);
        return;
    }
    ListaColores actual = lista;
    while(actual != NULL)
    {
        if(color_getNombre(actual->color) == nombre)
            return;
        actual = actual->siguiente;
    }
    coloresLista_agregarAlInicio(lista, nombre);
}

void coloresLista_borrarLista(ListaColores &lista)
{
    ListaColores actual = lista;
    while(actual != NULL)
    {
        ListaColores aux = actual;
        Color auxColor = actual->color;
        delete auxColor;
        delete aux;
        actual = actual->siguiente;
    }
    delete actual;
    lista = NULL;
}

