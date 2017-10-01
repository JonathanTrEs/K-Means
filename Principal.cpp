#include "Principal.h"

Principal::Principal(const char nombreFichero[]){
  puntos = Datos(nombreFichero);
}

void Principal::metodoKMeans(){
  //ESTO ES PAL CALCULO DE CENTROIDES
  int contPuntosCentroides = 0;
  vector <double> nuevoCentroide;
  vector <int> copiaAsignacion;
  //
  bool existe = false;
  bool salir = false;
  int k = 0;
  vector <int> random;
  int auxRandom = 0;
  cout << "Introduzca el nº de centroides qeu desea: " << endl;
  cout << ">";
  cin >> k;
  cout << endl;
  aKMeans = KMeans(k, puntos.getDimension(), puntos.getNumeroPuntos());
  srand (time(NULL));
  
  for(int i = 0; i < k; i++) {
    salir = false;
    while(!salir){
      existe = false;
      auxRandom = rand() % puntos.getNumeroPuntos();
      for(int j = 0; j < random.size(); j++) {
	if(random[j] == auxRandom)
	  existe = true;
      }
      if(!existe) {
	random.push_back(auxRandom);
	salir = true;
      }
    }
  }

  //Metemos los centroides
  for(int i = 0; i < random.size(); i++) {
    aKMeans.setCentroides(i,puntos.getPunto(random[i]));
  }
  
  for(int i = 0; i < puntos.getNumeroPuntos(); i++) {
    aKMeans.distanciaEuclidea(i,puntos.getPunto(i));
  }
  //HASTA AQUI ES EL VORAZ
  do { 
     copiaAsignacion = aKMeans.getAsignacion();
    //recalcular centroides
    nuevoCentroide.resize(puntos.getDimension());
    for(int i = 0; i < k; i++) {
      nuevoCentroide.assign(puntos.getDimension(), 0);
      contPuntosCentroides = 0;
      for(int j = 0; j < puntos.getNumeroPuntos(); j++) {
	if(aKMeans.getAsignacion(j) == i) {
	  contPuntosCentroides++;
	  for(int l = 0; l < puntos.getDimension(); l++) {
	    nuevoCentroide[l] += puntos.getPunto(i)[l];
	  }
	}
      }
      for(int j = 0; j < puntos.getDimension(); j++) {
	nuevoCentroide[j] /= contPuntosCentroides;
      }
      aKMeans.setCentroides(i,nuevoCentroide);
    }
    for(int i = 0; i < puntos.getNumeroPuntos(); i++) {
      aKMeans.distanciaEuclidea(i,puntos.getPunto(i));
    }
    cont++;
  }while(copiaAsignacion != aKMeans.getAsignacion());
  
  double numeroSse = 0.0;
  for(int i = 0; i < puntos.getNumeroPuntos(); i++) {
    numeroSse += aKMeans.sse(i, puntos.getPunto(i));
  }
  cout << "El SSE es: " << numeroSse << endl;
}



















