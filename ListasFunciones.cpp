#include <fstream>
#include <stdlib.h>
#include "ListasFunciones.h"


void mostrarFigurasOrdenadasPorFiguraColor(ListaFigura lista){
    if(lista == NULL) return ;
    cout << "---------------------------------------------------------------------------\n"<<endl;
    Nodo * actual = lista->inicio;
    Nodo * anterior = NULL;
    float sumaAreas = 0.0;
    while( actual != NULL){

        mostrarFigura(actual->figura);
        anterior = actual;
        actual = actual->siguiente;
        sumaAreas+=getArea(anterior->figura);
        if(actual != NULL){
           if( getTipo(anterior->figura) != getTipo(actual->figura) || getColor(anterior->figura) != getColor(actual->figura) )
               {
                    cout << "\n-El total gastado por las figuras de tipo |" << getTipo(anterior->figura) << "| y color |" << getColor(anterior->figura) << "| es : " << sumaAreas << endl << endl;
                    sumaAreas = 0.0;
                    cout << "---------------------------------------------------------------------------\n"<<endl;
               }
        }else{
            cout << "\n-El total gastado por las figuras de tipo |" << getTipo(anterior->figura) << "| y color |" << getColor(anterior->figura) << "| es : " << sumaAreas << endl;
            cout << "---------------------------------------------------------------------------\n"<<endl;
        }
            cout << endl;
    }
}


int leerArchivo(ListaFigura &listaFigura,ListaFigura &listaOrdenadaPorFigura,ListaFigura &listaOrdenadaPorIngreso,ListaFigura &listaOrdenadaPorFiguraColor,ListaColores &colores,string nombreArchivo){//cambiada
    ifstream archivo;
    string texto,aux;
    int i=0;
    int pos[3];
    float numero,valor1,valor2;

    archivo.open(nombreArchivo.c_str(), ios::in );

    if(archivo.fail()){
        return errorArchivo;
    }

    while(!archivo.eof()){
        if(!archivo.eof()){
            Figura figura=new struct EstructuraFigura();
            getline(archivo,texto);
            int longitud=texto.size();

        if(longitud!=0){
            //Buscamos las posiciones de los delimitadores
            obtenerDatosDeDelimitadores(texto,pos,' ',';');
            //TIPO
            aux=separarTexto(texto,0,pos[0]);
            figura->tipo=aux;
            //COLOR
            aux=separarTexto(texto,pos[0]+1,pos[1]);
            figura->color=aux;
            //Si el tercer delimitador es 0 es porque no EXISTE UN TERCER DELIMITADOR. Por lo tanto, es una figura que solo tiene un dato.
            if(pos[2]==-1){
                //SOLO UN VALOR - VALOR UNO
                aux=separarTexto(texto,pos[1]+1,longitud);
                numero = strtof((aux).c_str(),0);
                valor1=numero;
                valor2=0; //NULL

            }else{
                //VALOR UNO
                aux=separarTexto(texto,pos[1]+1,pos[2]);
                numero = strtof((aux).c_str(),0);
                valor1=numero;
                //VALOR DOS
                aux=separarTexto(texto,pos[2]+1,longitud);
                numero= strtof((aux).c_str(),0);
                valor2=numero;
            }
            figura->area=calcularArea(getTipo(figura),valor1,valor2);
            figura->orden=i;
            i++;

            //INSERTAR EN LA LISTA
            coloresLista_agregarAlInicioSinRepetir(colores, getColor(figura));
            insertarPorArea(listaFigura, figura);
            insertarAlFinal(listaOrdenadaPorIngreso,figura);
            insertarPorFiguraColor(listaOrdenadaPorFiguraColor, figura);
            insertarPorFigura(listaOrdenadaPorFigura, figura);
            }
        }
    }

    archivo.close();

    return bien;
}

int archivoExiste(string nombreArchivo){
    ifstream archivo;
    archivo.open(nombreArchivo.c_str(), ios::in );
    if(archivo.fail()){
        return errorArchivo;
    }
    archivo.close();
    return bien;
}

void obtenerDatosDeDelimitadores(string texto, int delimitadores[3],char primerDelimitador,char segundoDelimitador){
    delimitadores[0]=texto.find(primerDelimitador);
    delimitadores[1]=texto.find(primerDelimitador,delimitadores[0]+1);
    delimitadores[2]=texto.find(segundoDelimitador,delimitadores[1]+1);
}

string separarTexto(string texto, int inicio,int fin){
    string cadena;
    int j=0;
    for(int i=inicio;i<fin;i++){
        if(texto[i]==','){
            texto[i]='.';
        }
        cadena=cadena+texto[i];
        j++;
    }

return cadena;}


void mostrarOrdenDeIngresoPorColor(ListaFigura &listaFiguras, ListaColores &listaColores){
    if(listaFiguras == NULL || listaColores == NULL ) return;
    float suma = 0;
    Color aux;
    string auxColor;
    Nodo*actual=NULL;

    cout << "\tORDEN DE INGRESO POR COLOR:\n"<<endl;

    for(int i=0;i<coloresLista_getTamanio(listaColores);i++){       //Recorre todos los colores
        aux=coloresLista_obtenerColor(listaColores,i+1);
        auxColor=color_getNombre(aux);
        cout << "------------------------------------\n"<<endl;
        cout << "COLOR: |"<<auxColor<< "|\n"<<endl;
        actual=listaFiguras->inicio;
        while(actual!=NULL){

            if(getColor(actual->figura) == auxColor){
                mostrarFigura(actual->figura);
                suma+=getArea(actual->figura);
                }

            actual=actual->siguiente;
        }
        cout << "El total de plastico gastado por el color "<<auxColor<<" : | "<<suma<<" |"<<endl;
        suma=0;
        cout << endl;
    }
        cout << "------------------------------------\n"<<endl;
}


int cantidadDeFiguras(ListaFigura &lista){
    if(lista == NULL)return errorVacio;
    int cont=0,auxTipo;
    Nodo * actual = lista->inicio;
    int resultados[5]={0,0,0,0,0}; //Valor inicial. Si hay un 0 es porque no hay figura. Si hay un 1 es porque la hay.


    while(actual!=NULL){
        auxTipo=obtenerNumeroFigura(getTipo(actual->figura));
        if(auxTipo==0 && resultados[0]==0){
            cont++;
            resultados[0]=1;
        }
        if(auxTipo==1 && resultados[1]==0){
            cont++;
            resultados[1]=1;
        }
        if(auxTipo==2 && resultados[2]==0){
            cont++;
            resultados[2]=1;
        }
        if(auxTipo==3 && resultados[3]==0){
            cont++;
            resultados[3]=1;
        }
        if(auxTipo==4 && resultados[4]==0){
            cont++;
            resultados[4]=1;
        }
        actual=actual->siguiente;
    }

    return cont;
}

int mostrarTotalPorFigura(ListaFigura &listaOrdenadaPorFigura,int cantidadDeFiguras){
    if(listaOrdenadaPorFigura->inicio == NULL)return errorVacio;

    float suma=0;
    int cont=0; // La cantidad de veces que aparece la misma figura. Si es uno debe solo considerarse su area.
    Nodo* actual=listaOrdenadaPorFigura->inicio;
    string auxTipo,auxTipoSiguiente;

    cout << "\tCANTIDAD DE PLASTICO UTILIZADO POR FIGURA:\n "<<endl;

    if(actual->siguiente!=NULL)auxTipoSiguiente=getTipo(actual->siguiente->figura);

    cout << "------------------------------------------"<<endl;

    for(int i=0;i<cantidadDeFiguras;i++){

        auxTipo=getTipo(actual->figura);


        cout << "FIGURA: | "<<auxTipo<<" |\n"<<endl;

        while(actual!=NULL && auxTipo==auxTipoSiguiente){
            cont++;
            suma+=getArea(actual->figura);
            mostrarFigura(actual->figura);
            actual=actual->siguiente;
            if(actual!=NULL) auxTipoSiguiente=getTipo(actual->figura);
        }
        //El siguiente no es igual porque solo existe una sola figura.
        if(actual!=NULL && cont == 0){
            suma=getArea(actual->figura);
            mostrarFigura(actual->figura);
            actual=actual->siguiente;
        }

        cout << "Cantidad de plastico utilizado por la figura "<< auxTipo <<": "<< suma <<endl;
        cout << "\n------------------------------------------"<<endl;
        cout << endl;
        suma=0;
        cont=0;
    }
    return bien;
}

int mostrarListaOrdenadaPorArea(ListaFigura listaFigura){
    if(listaFigura==NULL) return errorEliminado;
    else if(listaFigura->inicio==NULL) return errorVacio;
    float sumaTotal=0.0;

    Nodo*actual=listaFigura->inicio;
    while(actual!=NULL){
        mostrarFigura(actual->figura);
        sumaTotal+=getArea(actual->figura);
        actual=actual->siguiente;
    }

    cout << "Total de plastico gastado : | "<< sumaTotal << " |"<<endl;
    cout << endl;

    return bien;
}

int agregarNuevaFigura(ListaFigura &listaFigura,ListaFigura &listaOrdenadaPorFigura,ListaFigura &listaOrdenadaPorIngreso,ListaFigura &listaOrdenadaPorFiguraColor,ListaColores &colores,string nombreArchivo){

            Figura figura = crearFiguraPorTeclado(nombreArchivo,colores);
            figura->orden=getTam(listaFigura);
            //INSERTAR EN LA LISTA
            coloresLista_agregarAlInicioSinRepetir(colores, getColor(figura));
            insertarPorArea(listaFigura, figura);
            insertarAlFinal(listaOrdenadaPorIngreso,figura);
            insertarPorFiguraColor(listaOrdenadaPorFiguraColor, figura);
            insertarPorFigura(listaOrdenadaPorFigura, figura);
            cout << "\n\tFIGURA AGREGADA CORRECTAMENTE\n"<<endl;

return bien;
}
