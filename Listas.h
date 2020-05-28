#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "Figura.h"
#include "Color.h"
#include "ColoresLista.h"
#include <string>

using namespace std;

enum Respuesta {errorVacio=0,errorPosicionMayorTamanio=-1,bien=1,errorEliminado=-2, errorNoEncontrado=-10,errorArchivo=-3};

struct Nodo
{
    Figura figura;
    Nodo *siguiente;
};
/*
        AXIOMAS
LA FIGURA TIENE QUE ESTAR CON MEMORIA RESERVADA Y CON TODOS SUS DATOS COMPLETADOS.
EL NODO SIGUIENTE, APUNTA AL NODO QUE SIGUE EN LA LISTA. EN EL CASO QUE SEA EL ULTIMO, ESTE APUNTA A NULLPTR.
*/


struct EstructuraListaFigura
{
    Nodo *inicio;
};
/*
        AXIOMAS
EL NODO INICIO DEBE SER INICIALMETNE NULLPTR, DESPUES DEBE SER SIEMPRE EL INICIO DE LA LISTA. EN ESTE CASO SERIA EL PRIMERO EN SER LEIDO.
EL TAM DEBE IR ACORDE A LA CANTIDAD DE NODOS QUE HAY EN LA LISTA, Y POR LO TANTO, EN LA CANTIDAD DE FIGURAS.
TAM DEBE SER SIEMPRE MAYOR O IGUAL A CERO, AUN ASI ES UNA VARIABLE QUE SOLO SE PUEDE PEDIR.
*/


typedef struct EstructuraListaFigura * ListaFigura;

//PRE-CONDICIONES: LA LISTA QUE SE PASA TIENE QUE ESTAR SIN CREAR 0 DESTRUIDA ANTERIOMENTE.
int crearListaFigura(ListaFigura &listaFigura);
//POST-CONDICIONES: DEVUELVE UN 1,QUE REPRESENTA UN BIEN, Y LA LISTA QUE SE PASO POR REFERENCIA FUE INICIALIZADA Y SE RESERVO MEMORIA.


//PRE-CONDICIONES: LA LISTA QUE SE PASA PUEDE SER QUE YA ESTE CREADA O DESTRUIDA, NO SE TIENE QUE PASAR SIN CREAR. LA FIGURA QUE SE PASA DEBE ESTAR CREADA SI O SI.
int insertarPorArea(ListaFigura &listaFigura,Figura figura);
//POST-CONDICIONES:
/*
    SI FUE ELIMINADA LA LISTA ANTERIORMENTE, DEVUELVE -2.
    SI SE PUDO INSERTAR, DEVUELVE 1.
    Y LA FIGURA SE INSERTA EN EL FINAL DE LA LISTA, PARA REPRESENTAR EN QUE ORDEN FUERON LEIDAS.
*/

//PRE-CONDICIONES: LA LISTA DEBE ESTAR CREADA. RECIBE UNA LISTA DONDE SE VA A INSERTAR LA FIGURA.
int insertarAlFinal(ListaFigura &listaFigura,Figura figura);
//POST-CONDICIONES: INSERTA FIGURA AL FINAL DE LA LISTA.

//PRE-CONDICIONES: LA LISTA DEBE ESTAR CREADA. SE DEBE MANDAR UNA FIGURA PARA INSERTAR. LA LISTA VA A QUEDAR ORDENADA POR FIGURA.
int insertarPorFigura(ListaFigura &listaF, Figura figura);
//POST-CONDICIONES: INSERTA A LA FIGURA SEGUN SU TIPO.

//PRE-CONDICIONES: Recibe una lista donde va a insertar una figura.
int insertarAlInicio(ListaFigura &lista, Figura figura);
//POST-CONDICIONES: Inserta la figura al inicio de la lista.

//PRE-CONDICIONES: Recibe una lista donde va a insertar una figura.
int insertarPorFiguraColor(ListaFigura &lista, Figura figura);
//POST-CONDICIONES: Inserta la figura agrupadas por Figura y Color, y a su vez ordenadas por área de mayor a menor.

//PRE-CONDICIONES: La lista pasada por parametro debería estar cargada.
string * getTipos(ListaFigura &lista);
//POST-CONDICIONES: Retorna un puntero a un vector de string de 5 posiciones que contienen la cantidad de tipos figuras que hay en la lista
//En el caso de que no se encuentren algunos tipos los rellena con "Vacio".

//PRE-CONDICIONES: Recibe una lista y un tipo de figura por parámetro, para buscar los colores que hayan sido cargados a ese tipo de figura.
string * getColoresPorTipo(ListaFigura &lista, string tipo);
//POST-CONDICIONES: Retorna un puntero a un vector de string de 10 posiciones que contienen la cantidad de colores que hay en la lista según el tipo de figura.
//En el caso de que no se encuentren algunos colores los rellena con "Vacio".


//PRE-CONDICIONES: Recibe una lista, un tipo de figura y un color de figura.
int getCantidadDeFigurasPorTipoYColor(ListaFigura &lista, string tipo, string color);
//PRE-CONDICIONES: Retorna la cantidad de figuras que hay según el tipo y color recibido.


//PRE-CONDICIONES: LA LISTA TIENE QUE ESTAR CREADA O DESTRUIDA, EL INT TIENE QUE SER MAYOR A CERO Y NO NECESARIAMENTE MENOR AL LARGO DE LA LISTA, LA FIGURA TIENE QUE ESTAR CREADA SI O SI
int obtenerFigura(ListaFigura listaFigura, int pos, Figura &obtenida);
//POST-CONDICIONES:
/*
    SI LA LISTA FUE ELIMINADA PREVIA A LA LLAMADA DE LA FUNCION, DEVUELVE -2.
    SI LA POSICION QUE SE PASA ES MAYOR O IGUAL AL TAMAÑO DE LA LISTA, DEVUELVE -1.
    SI LA LISTA ESTA VACIA, DEVUELVE 0.
    SI LA LISTS ESTA CARGADA Y LA POSICION ES VALIDA DEVUELVE 1, Y LA FIGURA QUE SE PASO POR REFENCIA ES LA QUE SE PIDE LA LISTA.
*/

//PRE-CONDICIONES: DEBE MANDARSE UNA LISTA CREADA PARA PODER LIBERAR SU MEMORIA.
int liberarMemoriaLista(ListaFigura &listaFigura);
//PRE-CONDICIONES: QUEDA LIBERADA LA MEMORIA QUE UTILIZABA LA LISTA.


//PREC-ONDICIONES: LA LISTA TIENE QUE ESTAR CREADA, TAMBIEN SE PUEDE PASAR UNA LISTA YA DESTRUIDA.
int destruirListaFigura(ListaFigura &listaFigura);
//POST-CONDICIONES:
/*
    SI LA LISTA FUE ELIMINADA ANTES DE LA LLAMADA,DEVUELVE -2.
    SI LA LISTA FUE CREADA ANTES DE LA LLAMADA, LIBERA LA MEMORIA DE LAS FIGURAS, NODOS Y DE LA LISTAFIGURA COMO TAL. DEVOLVIENDO 1.
    ADEMAS A LA LISTAFIGURA QUE SE PASA POR PARAMETRO SE LE ASIGNA UN NULLPTR, QUE SIRVE COMO COMPROBACION PARA LAS DEMAS FUMCIONES(ES EL CASO -2).
*/


//PRE-CONDICIONES: LA LISTA PUEDE SER CREADA, VACIA 0 DESTRUIDA.
int mostrarListaFigura(ListaFigura listaFigura);
//POST-CONDICIONES:
/*
    SI LA LISTA FUE DESTRUIDA ANTES DE LA LLAMADA, DEVUELVE -2.
    SI LA LISTA ESTA VACIA, DEVUELVE 0.
    SI LA LISTA ESTA CREADA, MUESTRA TODAS LAS FIGURAS Y DEVUELVE 1.
*/


//PRE-CONDICIONES: LA LISTA PUEDE SER CREADA, VACIA O DESTRUIDA.
int getTam(ListaFigura listaFigura);
//POST-CONDICIONES:
/*
    SI LA LISTA FUE DESTRUIDA ANTES DE LLAMADA, DEVUELVE -2.
    SINO DEVUELVE EL TAMAÑO DE LA LISTA.
    EN EL CASO QUE SEA UNA LISTA VACIA, VA A DEVOLVER UN 0.
*/


//PRE-CONDICIONES:LA FIGURA TIENE QUE SER CREADA SI O SI
int mostrarFigura(Figura&a);
//POST-CONDICIONES:
/*
    SE MUESTRA LA FIGURA A, DUELVE 1
*/


#endif // LISTAS_H_INCLUDED
