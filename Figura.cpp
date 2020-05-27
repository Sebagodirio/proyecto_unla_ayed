#include "Figura.h"
#include <math.h>
#include <fstream>
#include <stdlib.h>
#define PI 3.1415

using namespace std;

Figura crearFiguraPorTeclado(string nombreArchivo,ListaColores &lista){

    int controlTipo=0,controlColor=0,numFigura;

    string t,c,control;
    float uno,dos;

    while(controlTipo!=1){
    cout << "Digite el tipo de figura. Puede ingresar [circulo/cubo/rectangulo/triangulo/cilindro]: ";
    getline(cin,t);
    numFigura = obtenerNumeroFigura(t);
    if( 0 <= numFigura  &&  5 > numFigura ){
        controlTipo=1;
    }
    else{
        cout << "\nIngreso un tipo inexistente. Intentelo de nuevo.\n"<<endl;
    }
    }

    system("cls");

    while(controlColor!=1){

    cout << "Digite el color de la figura. Recuerde que como maximo pueden ser 10 colores.\nCantidad de colores: "<<coloresLista_getTamanio(lista)<<endl;
    cout << "Colores disponibles: ";
    coloresLista_mostrarTodosLosElementos(lista);
    cout<<endl;
    cout << "Color elegido: ";
    getline(cin,c);

    if( coloresLista_getTamanio(lista)<10 ){
        controlColor=1;
    }
    else{
        cout << "\nSupero el limite de colores. Intente eligiendo uno de los colores disponibles.\n"<<endl;
    }
    cout << "\n"<<endl;
    }

    system("cls");

    cout << "Ingrese el primer valor: ";
    getline(cin,control);
    uno= atoi(control.c_str());

    switch(numFigura){
    case circulo: dos=0;break;
    case cilindro: dos=1;break;
    case cubo: dos=0;break;
    case triangulo: dos=1;break;
    case rectangulo: dos=1;break;
    }

    if(dos==1){
    cout << "Ingrese el segundo valor: ";
    getline(cin,control);
    dos = atoi(control.c_str());
    }

    guardarFiguraArchivo(nombreArchivo,t,c,uno,dos);

    return crearFigura(t,c,uno,dos);
}

Figura crearFigura(string t,string c,float v1,float v2)
{
    Figura x=new struct EstructuraFigura();
    x->tipo=t;
    x->color=c;
    x->area=calcularArea(t,v1,v2);

    return x;
}

float calcularArea(string tipo,float v1,float v2)
{
    float area=0;
    int numero=obtenerNumeroFigura(tipo);
    switch(numero)
    {
    case circulo:
        area=PI*pow(v1,2);
        break;
    case cilindro:
        area=2*PI*v1*v2 + 2*PI*pow(v1,2);
        break;
    case cubo:
        area=6*pow(v1,2);
        break;
    case triangulo:
        area=(v1*v2)/2;
        break;
    case rectangulo:
        area=(v1*v2);
        break;
    default:
        break;
    }

    return area;
}

int mostrarFigura(Figura& a)
{
    cout << "Tipo: "<<getTipo(a)<<endl;
    cout << "Color: "<<getColor(a)<<endl;
    cout << "Num de ingreso: "<<getOrden(a)<<endl;
    cout << "Area: "<<getArea(a)<<endl;

    cout << endl;

    return 1;
}

int obtenerNumeroFigura(string tipo)
{
    if(tipo=="circulo")
    {
        return circulo;
    }
    if(tipo=="cilindro")
    {
        return cilindro;
    }
    if(tipo=="cubo")
    {
        return cubo;
    }
    if(tipo=="triangulo")
    {
        return triangulo;
    }
    if(tipo=="rectangulo")
    {
        return rectangulo;
    }
    return -1;
}

int guardarFiguraArchivo(string nombreArchivo,string tipo,string color,float valorUno,float valorDos){

    ofstream archivo;
    archivo.open(nombreArchivo.c_str(), ios::out | ios::app);

        if(archivo.fail()){
        return archivoInexistente;
        }

        if(valorDos==0){
            archivo<<tipo<<" "<<color<<" "<<valorUno<<endl;
        }
        else{
            archivo<<tipo<<" "<<color<<" "<<valorUno<<";"<<valorDos<<endl;
        }

    archivo.close();
    return figuraGuardada;

}


string getTipo(Figura &x)
{
    return x->tipo;
}

string getColor(Figura &x)
{
    return x->color;
}

float getArea(Figura &x)
{
    return x->area;
}

int getOrden(Figura &x)
{
    return x->orden;
}

int destruirFigura(Figura &x)
{
    delete x;
    x=NULL;
    return 1;
}

