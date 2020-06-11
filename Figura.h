#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include <string>
#include <iostream>
#include "ColoresLista.h"

using namespace std;

enum tiposErrores { archivoInexistente , figuraGuardada };
enum numerosFiguras {circulo,cilindro,cubo,triangulo,rectangulo};

struct EstructuraFigura
{
    string tipo;
    string color;
    float area;
    int orden;
};

/*          AXIOMAS
    TIPO debe ser el nombre de la figura. Puede ser: circulo, cilindro, triangulo, rectangulo o cubo.
    COLOR debe ser el color de la figura. La variedad de colores depende de como venga cargado el archivo. Hay 10 colores disponibles.
    AREA debe ser la cantidad de papel que necesita la figura. Es calculada con los dos valores que se leen en el archivo.
    ORDEN es el numero de ingreso de la figura.
*/


typedef struct EstructuraFigura * Figura;

//PRE-CONDICIONES: SE DEBE RECIBIR POR PARAMETRO DOS STRINGS Y DOS FLOAT.
Figura crearFigura(string tipo,string color,float v1,float v2);
//POS-CONDICIONES: DEVUELVE UNA FIGURA CON LOS DATOS MANDADOS POR PARAMETRO.



//PRE-CONDICIONES: DEBE MANDARSE UN STRING QUE INDICA QUE TIPO DE FIGURA ES.
int obtenerNumeroFigura(string tipo);
//POST-CONDICIONES: DEVUELVE UN NUMERO DEPENDIENDO QUE FIGURA ES.

//PRE-CONDICIONES: SE DEBE RECIBIR POR PARAMETRO UN STRING JUNTO A LOS DOS VALORES DE LA FIGURA.
float calcularArea(string tipo,float v1,float v2);
//POST-CONDICIONES: DEVUELVE EL VALOR DEL AREA DE LA FIGURA.

int guardarFiguraArchivo(string nombreArchivo,string tipo,string color,float valorUno,float valorDos);

/*##########################################################*/

int mostrarFigura(Figura& a);



string getTipo(Figura &x);

string getColor(Figura &x);

float getArea(Figura &x);

int getOrden(Figura &x);

int destruirFigura(Figura &x);

#endif // FIGURA_H_INCLUDED
