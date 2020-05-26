#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;
/*
    Axiomas: El string debe ser un color, no seria correcto en otros casos.
*/
struct EstructuraColor
{
    string nombre;
};

typedef struct EstructuraColor * Color;

//Pre-condiciones: Se tiene que pasar un string que representaria el nombre del color.
//Post-condiciones: Se retorna un Color con la memoria reservada y con el nombre que se le paso.
Color crearColor(string nombre);


//Pre-condiciones: Se tiene que pasar un color ya creado con la funcion "crearColor(string)".
//Post-condiciones: Se se asigna el nuevo nombre a ese color.
void color_setNombre(Color color, string nombre);


//Pre-condiciones: Se tiene que pasar un color ya creado con la funcion "crearColor(string)".
//Post-condiciones: Se retorna el nombre del color que se paso.
string color_getNombre(Color color);

#endif // COLOR_H_INCLUDED
