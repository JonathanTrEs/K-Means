#include "Datos.h"

/** Constructor */
Datos::Datos(const char nombreFichero[]) {
  int numeroPuntos = 0;
  dimension = 0;
  leerDatos(nombreFichero);
}

/** Funcion que redimensiona la matriz de puntos segun el numero de puntos que tengamos
 * y segun las dimensiones que tengan los puntos */
void Datos::redimensionarMatriz() {
  datos.resize(numeroPuntos);
  for(int i = 0; i < numeroPuntos; i++)
    datos[i].resize(dimension);
  
}
/** Funcion que lee los datos del fichero */
void Datos::leerDatos(const char nombreFichero[]) {
  string dato;
  ifstream textfile;
  textfile.open(nombreFichero);
  if(textfile.is_open()) {
    textfile >> dato;
    numeroPuntos = atoi(dato.c_str());
    textfile >> dato;
    dimension = atoi(dato.c_str());
    redimensionarMatriz();
    for(int i = 0; i < numeroPuntos; i++) {
      for(int j = 0; j < dimension; j++) {
	textfile >> dato;
	datos[i][j] = atof(dato.c_str());
      }
    }
  }
  else {
    cout << "ERROR: Imposible cargar el fichero " << nombreFichero << endl;
  }
  textfile.close();
}
/** Funcion que muestra los datos recogidos por pantalla */
void Datos::mostrarDatos(){
  cout << "Numero de puntos: " << numeroPuntos << endl;
  cout << "Dimensiones: " << dimension << endl;
  for(int i = 0; i < numeroPuntos; i++) {
    cout << "Punto " << i+1 << ": ";
    for(int j = 0; j < dimension; j++) {
      cout << datos[i][j] << " ";
    }
    cout << endl;
  }
}

//GETTER Y SETTERS
int Datos::getDimension() {
  return dimension;
}

int Datos::getNumeroPuntos() {
  return numeroPuntos;
}

vector <double> Datos::getPunto(int pos) {
  return datos[pos];
}