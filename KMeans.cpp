#include "KMeans.h"

KMeans::KMeans(int nCentroides, int dimension, int nPuntos) {
  centroides.resize(nCentroides);
  for(int i = 0; i < nCentroides; i++) {
    centroides[i].resize(dimension);
  }
  asignacion.resize(nPuntos);
}
void KMeans::calcularCentroides() {
  
}
void KMeans::distanciaEuclidea(int pos,vector <double> punto) {
  int auxDistancia = 0;
  int distanciaMenor = 0;
  int indiceCentroide = 0;
  for(int i = 0; i < centroides.size(); i++) {
    auxDistancia = 0;
    for(int j = 0; j < centroides[i].size(); j++) {
      auxDistancia += (centroides[i][j] - punto[j])*(centroides[i][j] - punto[j]);
    }
    if(i == 0)
      distanciaMenor = auxDistancia;
    else if(distanciaMenor > auxDistancia) {
      distanciaMenor = auxDistancia;
      indiceCentroide = i;
    }
  }
  asignacion[pos] = indiceCentroide;
}

void KMeans::setCentroides(int pos, vector <double> centro){
  centroides[pos] = centro;
}

void KMeans::mostrarCentroides() {
  for(int i = 0; i < centroides.size(); i++) {
    cout << "Centroide " << i+1 << " :";
    for(int j = 0; j < centroides[i].size(); j++) {
      cout << " " << centroides[i][j] << " ";
    }
    cout << endl;
  }
}
void KMeans::mostrarAsignacion() {
  for(int i = 0; i < asignacion.size(); i++) {
    cout << "Punto " << i+1 << " : " << asignacion[i] << endl;
  }
}
int KMeans::getAsignacion(int pos) {
  return asignacion[pos];
}

vector<int> KMeans::getAsignacion() {
  return asignacion;
}

double KMeans::sse(int pos, vector <double> punto){
  int auxCentro = 0;
  double resultado = 0.0;
  auxCentro = asignacion[pos];
  for(int j = 0; j < centroides[auxCentro].size(); j++) {
    resultado += sqrt((centroides[auxCentro][j] - punto[j])*(centroides[auxCentro][j] - punto[j]));
  }
  return resultado;
}








