
#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

#include <time.h>

#include "Datos.h"
#include "KMeans.h"

using namespace std;

class Principal {
  private:
    Datos puntos;
    KMeans aKMeans;
  public:
    Principal(const char nombreFichero[]);
    ~Principal(){};
    void metodoKMeans();
};

#endif