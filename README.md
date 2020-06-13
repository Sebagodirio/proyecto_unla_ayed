# proyecto__unla_ayed
Proyecto de empresa fabricadora de figuras plasticas de diferente formas y colores.

## Proposito

Este proyecto es un simulacro para una empresa que es productora de articulos plasticos de diferentes formas y colores. Esta posee una maquina la cual es la encargada de inyectar el color, el cual recibira los datos de la orden de produccion a traves del software, el cual a su vez, traera los datos un archivo formato txt.

## Funcionalidades

El software cuenta con una estructura la cual a travez de la lectura del archivo txt almacenara el tipo de figura, su color, y la cantidad de plastico necesario para su produccion (al ser figuras en 2 dimensiones, la cantidad de plastico se trata del area de cada figura). **El software le da la posibilidad al usuario** de mostrarle al usuario las figuras ordenadas por la cantidad de plastico empleado para cada una, desde la que mas plastico se necesita, hasta la que menos. El usuario tambien podra recibir la informacion del **total** de plastico utilizado por cada figura, como tambien asi el total de plastico utilizado por figura por color. Por ultimo, se podra ver el orden de ingreso de las figuras por color.

### Funcion insertarPorFiguraColor()
La función insertarPorFiguraColor busca insertar Figuras en una lista con la siguiente lógica.

Primero busca agrupar en forma consecutiva a todas las figuras del mismo tipo, ejemplo:

    Circulo verde 22.3
    Circulo azul 33
    Circulo verde 43.2
    Triangulo rojo 55.5
    Triangulo amarillo 22
    Triangulo rojo 121
    Cubo azul 22
    Cubo rosa 213
    Cubo rosa 341

Esto lo hace utilizando una función que se llama **getTipos(ListaFigura &lista)** que lo que hace la función es devolver un puntero de tipo string, apuntando a una dirección de memoria donde a partir de esa posición a 9 posiciones más (en total 10 posiciones), se almacenan los nombres de los tipos de figura que contiene actualmente la lista mandada por parámetro (En caso de solo haber 3 tipos de figuras en la lista, se rellena con "Vacio"). 
Una vez obtenidos los tipos de figuras que hay en la lista, se revisa si el tipo de la figura que se recibió por parámetro ya existe en la lista, de no existir, la incerta en la primera posición, si el tipo de la figura ya existe en la lista, se realiza otra lógica, ordenando a la figura por su color, ejemplo:

    Circulo azul 33
    Circulo verde 22.3
    Circulo verde 43.2
    Triangulo amarillo 22
    Triangulo rojo 55.5
    Triangulo rojo 121
    Cubo azul 22
    Cubo rosa 213
    Cubo rosa 341

El programa solo llega hasta esta parte si el tipo de la figura mandada por parámetro existe en la lista. Acá se utiliza una función **getColoresPorTipo(ListaFigura &lista, string tipo)**, lo que hace es retornar un puntero de tipo string, apuntando a una dirección de memoria donde a partir de esa posición a 4 posiciones más (en total 5 posiciones), se almacenan los colores que posee actualmente ese tipo de figura en la lista.
Lo que se hace con esa información es, primero recorrer la lista hasta llegar a las figuras que tengan el mismo tipo que la figura mandada por parámetro, una vez que llega hasta ahí se verifica si existe o no el color de la figura mandada por parámetro con las figuras del mismo tipo que ya están en la lista, en el caso de no existir se inserta al principio, en el ejemplo anterior si insertaramos un Triangulo color Verde quedaría así:

    Triangulo verde 33.2
    Triangulo amarillo 22
    Triangulo rojo 55.5
    Triangulo rojo 121

Una vez realizadas estas verificaciones, ya se agrupan las figuras por tipo y color. Ahora queda realizar la última verificación que es el area de la figura, la finalidad de esta función es agrupar dentro de la lista a las figuras por mismo Tipo, mismo Color y a su vez dentro de los colores ordenadas de mayor a menor según su área, ejemplo:

    Circulo azul 33
    Circulo verde 43.2
    Circulo verde 22.3
    Triangulo verde 33.2
    Triangulo amarillo 22
    Triangulo rojo 121
    Triangulo rojo 55.5
    Cubo azul 22
    Cubo rosa 341
    Cubo rosa 213

Para realizar esto, se utiliza una función **getCantidadDeFigurasPorTipoYColor(ListaFigura &lista, string tipo, string color)** que devuelve un entero de la cantidad de figuras que hay dado un tipo y un color. 
Lo que se hace es recorrer la lista hasta encontrar las figuras que coincidan con el mismo tipo y color que la figura mandada por parámetro, una vez llegado hasta esas figuras, se revisa si el área de la figura es mayor que la que se esta recorriendo actualmente en la lista, de ser así, la inserta antes que esa. Ejemplo, si se insertara un Cubo rosa de área 230:

    Cubo azul 22
    Cubo rosa 341
    Cubo rosa 230
    Cubo rosa 213
    
## Procedimiento

El software fue pensado para informar los datos de una manera dinamica, para un correcto manejo de la memoria. Todas las funcionalidades fueron llevadas a cabo a traves de listas enlazadas simples. En estas se guardaron la informacion contenida en el archivo txt de distintas maneras dependiendo la funcionalidades necesarias. Los colores tambien fueron manejados de una forma dinamica con utilizacion de listas, previniendo asi el futuro deseo de la empresa de agregar un nuevo color a su stock o eliminar uno, de la misma manera el usuario podra agregar una nuevo a figura que se guardaria en el archivo txt.

*Integrantes. Grupo numero 1.*

*DE LA FUENTE EZEQUIEL-
*GARCIA MISA CAMILA
*GODIRIO SEBASTIAN
*GOMEZ NICOLAS

