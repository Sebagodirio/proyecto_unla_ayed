#include "Color.h"

using namespace std;

Color crearColor(string nombre)
{
    Color c = new struct EstructuraColor;
    c->nombre = nombre;
    return c;
}

void color_setNombre(Color color, string nombre)
{
    color->nombre = nombre;
}

string color_getNombre(Color color)
{
    return color->nombre;
}
