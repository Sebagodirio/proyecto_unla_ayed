#include "Figura.h"
#include "Color.h"
#include "Listas.h"
#include "ColoresLista.h"
#include <iostream>

using namespace std;


int crearListaFigura(ListaFigura &listaFigura){
    listaFigura = new struct EstructuraListaFigura();
    listaFigura->inicio = NULL;
    return bien;
}

int insertarPorArea(ListaFigura &listaFigura,Figura figura){
    if(listaFigura==NULL) return errorEliminado;
    //RESERVO MEMORIA PARA EL NUEVO NODO
    Nodo* nuevoNodo=new struct Nodo();
    nuevoNodo->figura=figura;
    nuevoNodo->siguiente=NULL;
    //ASIGNO AUX1 AL INICIO Y DECLARO AUX2
    Nodo*aux1=listaFigura->inicio;
    Nodo* aux2;
    //RECORRO LA LISTA
    while((aux1)!=NULL && aux1->figura->area > figura->area){
        //AL ESCRIBIRSE ORDENADA NODO1>NODO2
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    //SI NO ENTRO EN EL WHILE VA AL INICIO
    if(listaFigura->inicio==aux1){
        listaFigura->inicio=nuevoNodo;
    }else{//
        aux2->siguiente=nuevoNodo;
    }
    nuevoNodo->siguiente=aux1;
    return bien;
}

int insertarPorFigura(ListaFigura &listaFigura, Figura figura){
    if(listaFigura==NULL) return errorEliminado;
    //RESERVO MEMORIA PARA EL NUEVO NODO
    Nodo* nuevoNodo=new struct Nodo();
    nuevoNodo->figura=figura;
    nuevoNodo->siguiente=NULL;
    //ASIGNO AUX1 AL INICIO Y DECLARO AUX2
    Nodo*aux1=listaFigura->inicio;
    Nodo* aux2;
    //RECORRO LA LISTA
    int numeroFigura=obtenerNumeroFigura(figura->tipo);
    while((aux1)!=NULL && obtenerNumeroFigura(aux1->figura->tipo) > numeroFigura){
        //AL ESCRIBIRSE ORDENADA NODO1>NODO2
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    //SI NO ENTRO EN EL WHILE VA AL INICIO
    if(listaFigura->inicio==aux1){
        listaFigura->inicio=nuevoNodo;
    }else{//
        aux2->siguiente=nuevoNodo;
    }
    nuevoNodo->siguiente=aux1;
    return bien;
}

int insertarAlInicio(ListaFigura &lista, Figura figura){
    if(lista == NULL) return errorEliminado;
    Nodo * nuevoNodo = new struct Nodo();
    nuevoNodo->figura = figura;
    nuevoNodo->siguiente = lista->inicio;
    lista->inicio = nuevoNodo;
    return bien;
}

int obtenerFigura(ListaFigura listaFigura, int pos, Figura &obtenida){
    if(listaFigura==NULL) return errorEliminado;
    else if(pos>= getTam(listaFigura)) return errorPosicionMayorTamanio;
    else if(listaFigura->inicio==NULL) return errorVacio;

    int posAux=0;
    Nodo* nodoAux=listaFigura->inicio;
    while(nodoAux!=NULL && posAux<pos){
        nodoAux=nodoAux->siguiente;
        posAux++;
    }
    obtenida=nodoAux->figura;
    return bien;
}

int destruirListaFigura(ListaFigura &listaFigura){
    if(listaFigura==NULL) return errorEliminado;
    if(listaFigura->inicio==NULL){
        delete listaFigura;
        return bien;
    }
    while(listaFigura->inicio!=NULL){
        Nodo*aux=listaFigura->inicio;
        Figura auxFigura=listaFigura->inicio->figura;
        listaFigura->inicio=listaFigura->inicio->siguiente;
        destruirFigura(auxFigura);
        delete aux;
        aux=NULL;
    }
    delete listaFigura;
    listaFigura=NULL;
    return bien;
}

int mostrarListaFigura(ListaFigura listaFigura){
    if(listaFigura==NULL) return errorEliminado;
    else if(listaFigura->inicio==NULL) return errorVacio;

    Nodo*actual=listaFigura->inicio;
    while(actual!=NULL){
        mostrarFigura(actual->figura);
        actual=actual->siguiente;
    }
    return bien;
}

int getTam(ListaFigura listaFigura){
    if(listaFigura==NULL) return errorEliminado;
    Nodo* actual=listaFigura->inicio;
    int a=0;
    while(actual!=NULL){
        actual=actual->siguiente;
        a++;
    }
    return a;
}

string * getTipos(ListaFigura &lista){
    if(lista == NULL) return NULL;
    string * tipos = new string[5];
    for(int i = 0 ; i < 5 ; i++){
        tipos[i] = "Vacio";
    }
    Nodo *actual = lista->inicio;
    int cantidadActualDeTipos = 0;
    while(actual != NULL){
        bool existeElTipo = false;
        for(int i=0 ; i < cantidadActualDeTipos && tipos[i] != "Vacio" && !existeElTipo ; i++){
            if(getTipo(actual->figura) == tipos[i]){
                existeElTipo = true;
            }
        }
        if(!existeElTipo){
            tipos[cantidadActualDeTipos] = getTipo(actual->figura);
            cantidadActualDeTipos++;
        }
        actual = actual->siguiente;
    }
    return tipos;
}

string * getColoresPorTipo(ListaFigura &lista, string tipo){
    if(lista == NULL) return NULL;
    string  * colores = new string[10];
    for(int i = 0 ; i < 10 ; i++){
        colores[i] = "Vacio";
    }
    Nodo *actual = lista->inicio;
    int cantidadActualDeColores = 0;
    while(actual != NULL){
        if(getTipo(actual->figura) == tipo){
            bool existeElColor = false;
            for(int i = 0 ; i < cantidadActualDeColores && colores[i] != "Vacio" && !existeElColor ; i++){
                if(getColor(actual->figura) == colores[i])
                    existeElColor = true;
            }
            if(!existeElColor){
                colores[cantidadActualDeColores] = getColor(actual->figura);
                cantidadActualDeColores++;
            }
        }
        actual = actual->siguiente;
    }

    return colores;
}

int getCantidadDeFigurasPorTipoYColor(ListaFigura &lista, string tipo, string color){
    if(lista == NULL) return errorEliminado;
    int cont = 0;
    Nodo * actual = lista->inicio;
    while( actual != NULL){
        if(getTipo(actual->figura) == tipo && getColor(actual->figura) == color){
            cont++;
        }
        actual = actual->siguiente;
    }
    return cont;
}

int insertarPorFiguraColor(ListaFigura &lista, Figura figura){
    if(lista == NULL) return errorEliminado;

    Nodo *nuevoNodo = new struct Nodo();
    nuevoNodo->figura = figura;

    if(lista->inicio == NULL){
        lista->inicio = nuevoNodo;
        return bien;
    }

    string * nombresDeTipos = getTipos(lista);
    bool tipoYaExisteEnLaLista = false;

    for(int j = 0; j < 5  && *(nombresDeTipos + j) != "Vacio" && !tipoYaExisteEnLaLista ; j++){
        if( *(nombresDeTipos + j) == getTipo(figura) ){
            tipoYaExisteEnLaLista = true;
        }
    }

    delete []nombresDeTipos;

    if( !tipoYaExisteEnLaLista ){
        insertarAlInicio(lista, figura);
        return bien;
    }

    Nodo *anterior = NULL;
    Nodo *actual = lista->inicio;
    string * nombresDeColores;

    int i = 0;
    do{
        if(getTipo(actual->figura) == getTipo(figura)){

            bool colorYaExisteEnElTipoDeFigura = false;

            nombresDeColores = getColoresPorTipo(lista, getTipo(figura));

            for( int j = 0 ; j < 10 && *(nombresDeColores + j) != "Vacio" && !colorYaExisteEnElTipoDeFigura ; j++){
                if( *(nombresDeColores + j) == getColor(figura) ){
                    colorYaExisteEnElTipoDeFigura = true;
                }

            }

            if( !colorYaExisteEnElTipoDeFigura ){
                if(anterior == NULL){
                    nuevoNodo->siguiente = actual;
                    lista->inicio = nuevoNodo;
                }else{
                    anterior->siguiente = nuevoNodo;
                    nuevoNodo->siguiente = actual;
                }
                delete [] nombresDeColores;
                return bien;
            }

            int cantFigurasPorTipoyColor = getCantidadDeFigurasPorTipoYColor(lista, getTipo(figura), getColor(figura));
            i = 0;

            do{
                if( getArea(figura) >= getArea(actual->figura)
                   && getColor(actual->figura) == getColor(figura)){

                    if(anterior == NULL){
                        nuevoNodo->siguiente = actual;
                        lista->inicio = nuevoNodo;
                    }else{
                        anterior->siguiente = nuevoNodo;
                        nuevoNodo->siguiente = actual;
                    }
                    return bien;

                }else if(i == cantFigurasPorTipoyColor){
                    anterior->siguiente = nuevoNodo;
                    nuevoNodo->siguiente = actual;
                    return bien;
                }

                anterior = actual;

                if(getColor(actual->figura) == getColor(figura)){
                    i++;
                }
                actual = actual->siguiente;
            }while(actual->siguiente != NULL && i <= cantFigurasPorTipoyColor);


        }

        anterior = actual;
        actual = actual->siguiente;

    }while(actual != NULL);

    return bien;
}

int liberarMemoriaLista(ListaFigura &listaFigura) {
    if(listaFigura==NULL) return errorEliminado;
    Nodo* actual=listaFigura->inicio;
    while(actual!=NULL){
        Nodo* aux=actual;
        actual=actual->siguiente;
        delete aux;
    }
    delete listaFigura;
    return bien;
}
