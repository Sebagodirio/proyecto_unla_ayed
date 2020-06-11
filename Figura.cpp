#include "Figura.h"
#include <math.h>
#include <fstream>
#include <stdlib.h>
#define PI 3.1415

using namespace std;



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

