#ifndef DATOS_H_
#define DATOS_H_	

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/** Clase que almacena los datos. Es Decir los cada punto con sus coordenadas
 * atributos:
 *	numeroPuntos: Entero que almacena el numero de puntos que hay en el fichero
 * 	dimension: Entero que almacena las dimensiones qeu tendra cada punto
 * 	datos: Matriz que almacenara las dimensiones de cada punto
 * metodos:
 * 	constructor
 * 	destructor
 * 	leerDatos: funcion que lee los datos desde fichero y los almacena
 * 	redimensionarMatriz: funcion que tras leer el numero de puntos y las dimensiones
 * 			     redimensiona la Matriz.
 * 	mostrarDatos: Funcion que muestra datos por pantalla.
 */
class Datos {
  private:
    int numeroPuntos;
    int dimension;
    vector < vector <double> > datos;
  public:
    Datos(){};
    Datos(const char nombreFichero[]);
    ~Datos(){};
    void leerDatos(const char nombreFichero[]);
    void redimensionarMatriz();
    void mostrarDatos();
    
    int getDimension();
    int getNumeroPuntos();
    vector <double> getPunto(int pos);
};

#endif