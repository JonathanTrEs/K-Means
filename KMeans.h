#ifndef KMEANS_H_
#define KMEANS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class KMeans {
  private:
    vector < vector <double> > centroides;
    vector <int> asignacion;
  public:
    KMeans(){};
    KMeans(int, int, int);
    ~KMeans(){};
    void calcularCentroides();
    void distanciaEuclidea(int, vector <double>);
    void mostrarCentroides();
    void mostrarAsignacion();
    
    void setCentroides(int, vector <double>);
    int getAsignacion(int);
    vector <int> getAsignacion();
    double sse(int, vector <double>);
};

#endif