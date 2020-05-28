#include <iostream>
#include <stdlib.h>
#include <string>
#include "Figura.h"
#include "Listas.h"
#include "ListasFunciones.h"

using namespace std;

/*
        ALGORITMOS Y ESTRUCTURA DE DATOS

        GRUPO NUMERO 1
        -DE LA FUENTE EZEQUIEL
        -GARCIA MISA CAMILA
        -GODIRIO SEBASTIAN
        -GOMEZ NICOLAS

*/


int menu();
string pedirNombreArchivo();

int main()
{
    int opcion = 10;

    cout << "\n\n\n\t\tBienvenido.\n\n\n"<<endl;

    ListaFigura listaOrdenadaPorArea = NULL;
    ListaFigura listaOrdenadaPorFigura = NULL;
    ListaFigura listaOrdenadaPorFiguraColor = NULL;
    ListaFigura listaOrdenadaPorIngreso = NULL;
    ListaColores colores = NULL;
    crearListaFigura(listaOrdenadaPorArea);
    crearListaFigura(listaOrdenadaPorFigura);
    crearListaFigura(listaOrdenadaPorFiguraColor);
    crearListaFigura(listaOrdenadaPorIngreso);
    system("pause");
    system("cls");
    string nombreArchivo=pedirNombreArchivo();

    leerArchivo(listaOrdenadaPorArea,listaOrdenadaPorFigura,listaOrdenadaPorIngreso,listaOrdenadaPorFiguraColor,colores,nombreArchivo);
    int cantFiguras=cantidadDeFiguras(listaOrdenadaPorArea);


    while(opcion!=6)
    {
        system("pause");
        system("cls");
        opcion=menu();
        system("cls");

        cout << "\n\n";
        switch(opcion)
        {

        case 1: cout << "\tFIGURAS ORDENADAS DE MAYOR A MENOR POR LA CANTIDAD DE PLASTICO UTILIZADO:\n"<<endl;
                mostrarListaOrdenadaPorArea(listaOrdenadaPorArea);
                break;
        case 2: mostrarTotalPorFigura(listaOrdenadaPorFigura,cantFiguras);
                break;
        case 3: cout << "\tCANTIDAD DE PLASTICO GASTADO POR FIGURA-COLOR:\n"<<endl;
                mostrarFigurasOrdenadasPorFiguraColor(listaOrdenadaPorFiguraColor);
                break;
        case 4: mostrarOrdenDeIngresoPorColor(listaOrdenadaPorArea,colores);
                break;
        case 5: agregarNuevaFigura(listaOrdenadaPorArea,listaOrdenadaPorFigura,listaOrdenadaPorFiguraColor,colores,nombreArchivo);
                break;

        case 6: cout << "\n\tGracias por utilizar nuestro programa.\n"<<endl;
                break;
        default:cout << "Ingreso una opcion incorrecta. Vuelva a intentarlo: "<<endl;
        }
    }

    destruirListaFigura(listaOrdenadaPorArea);
    liberarMemoriaLista(listaOrdenadaPorFigura);
    liberarMemoriaLista(listaOrdenadaPorFiguraColor);
    liberarMemoriaLista(listaOrdenadaPorIngreso);
    coloresLista_borrarLista(colores);

    return 0;
}

int menu()
{
    int opcion;
    string opcionString;
    cout << "----------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\t||MENU||\n\nIngrese un numero para:\n"<<endl;
    cout << "[1] Mostrar todas las figuras ordenadas por la cantidad de plastico utilizado."<<endl;
    cout << "[2] Mostrar el total de plastico utilizado por figura."<<endl;
    cout << "[3] Mostrar el total de plastico utilizado por figura-color."<<endl;
    cout << "[4] Mostrar el orden de ingreso de las figuras por color."<<endl;
    cout << "[5] Agregar una nueva figura."<<endl;
    cout << "[6] Mostrar figuras ordenadas por orden de ingreso."<<endl;
    cout << "[7] Salir del programa."<<endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------"<<endl;
    cout << "Opcion: ";
    getline(cin,opcionString);
    opcion= atoi(opcionString.c_str());

    return opcion;
}

string pedirNombreArchivo(){
    string nombre;
    int control=0;

    while(control!=bien){
        nombre="";
        cout << "Ingrese el nombre del archivo donde se encuentran las figuras: \n[NOTA] Solo ingrese el nombre (sin el .txt) || Si ingresa el numero 1 se leera archivo.txt por defecto."<<endl;
        getline(cin,nombre);
        if(nombre == "1")nombre="archivo";
        nombre += ".txt";

        cout << "El nombre ingresado del archivo es: "<<nombre<<endl;

        control=archivoExiste(nombre);
        if(control==bien){
            cout << "\nARCHIVO ENCONTRADO CORRECTAMENTE.\n\n";
            return nombre;
        }

        else{
        cout << "\nERROR. EL ARCHIVO NO EXISTE.\n\n";
        }
    }
    return "vacio";
}
