#ifndef COLORESLISTA_H_INCLUDED
#define COLORESLISTA_H_INCLUDED
#include "Color.h"
#include <string>

using namespace std;
/*
Axiomas:  
-siguiente debe apuntar al siguiente nodo, en el caso que este sea el ultimo debe ser NULL.
*/
struct EstructuraListaColor
{
    Color color;
    int pos;
    struct EstructuraListaColor * siguiente;
};

typedef struct EstructuraListaColor * ListaColores;

//Pre-condiciones: La lista puede ser igual a NULL o puede ya tener un inicio.
//Post-condiciones: Se crea una lista si es NULL sino se asing al inicio este nuevoColor.
void coloresLista_agregarAlInicio(ListaColores &lista, string nombre);

//Pre-condiciones: La lista puede ser igual a NULL o puede ya estar iniciada.
//Post-condiciones: : Se crea una lista si es NULL sino se insertar en el final este nuevoColor.
void coloresLista_agregarAlFinal(ListaColores &lista, string nombre);

//Pre-condiciones: La lista puede ser NULL o puede ya estar iniciada.
//Post-condiciones: Se inserta al final de la lista si no se encontraba en esta previamente.
void coloresLista_agregarAlFinalSinRepetir(ListaColores &lista, string nombre);

//Pre-condiciones: La lista puede ser NULL o puede ya estar iniciada.
//Post-condiciones: La inserta en el inicio si no la encuentra, en el caso que la encuentre no hace nada.
//Mas eficiente que agregarAlFinalSinRepetir.
void coloresLista_agregarAlInicioSinRepetir(ListaColores &lista, string nombre);//La usada en el tp.

//Pre-condiciones: La lista no debe estar creada anteriormente.
//Post-condiciones: Se crea el primer nodo de una lista la cual tiene a un color con el nombre que se paso por parametro.
void coloresLista_crearLista(ListaColores &lista, string nombre);

//Pre-condiciones: La lista puede ser igual a NULL o puede ya estar iniciada.
//Post-condiciones: Si es NULL no muestra nada, sino la muestra hasta llegar a NULL.
void coloresLista_mostrarTodosLosElementos(ListaColores lista);

//Pre-condiciones:  La lista debe estar creada, el indice debe ser mayor a 0.
//Post-condiciones: Si existe el indice dado devuelve el color, sino retorna NULL.
Color coloresLista_obtenerColor(ListaColores &lista, int indice);

//Pre-condiciones: La lista puede ser NULL o estar creada anteriormente.
//Post-condiciones: Si encuentra el nombre, devuelve el numero de la posicion. Sino devuelve 0
int coloresLista_indiceDelColor(ListaColores &lista, string nombre);

//Pre-condiciones:  La lista puede ser NULL o estar creada anteriormente.
//Post-condiciones:  Devuelve 0 si es NULL o la recorre hasta llegar a NULL y da el tamaño.
int coloresLista_getTamanio(ListaColores lista);

//Pre-condiciones: La lista tiene que estar creada.
//Post-condiciones: La lista con todos sus nodos y colores es borrada.
void coloresLista_borrarLista(ListaColores &lista);


#endif // COLORESLISTA_H_INCLUDED
