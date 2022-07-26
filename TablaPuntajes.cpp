#include "TablaPuntajes.h"
#include <algorithm>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

TablaPuntajes::TablaPuntajes(string new_n, int new_p) {
	
	//cargar del archivo bin los puntajes del juego.
	ifstream cargar("mejores_puntajes.dat",ios::binary|ios::trunc);
	Puntaje aux;
	while(cargar.read(aux.nombre,sizeof(aux.nombre)) ){ //aux.nombre no necesita de reinterpret_cast porque ya es un arreglo de char.
		// en sizeof se coloca (aux.nombre) porque no todos los nombres tienen la misma cant de char.
		cargar.read(reinterpret_cast<char*>(&aux.puntos),sizeof(int));
		ranking_p.push_back(aux);
	}
	cargar.close();
	
	/*llamo a la funcion que compara y acomoda los puntajes
	this->Ingresar(new_n,new_p);*/
}

///compara los puntajes para cambiar la posicion
int comparar(const Puntaje &a, const Puntaje &b){
	return a.puntos<b.puntos; 
}
//

void TablaPuntajes::Ingresar(string new_nom, int new_punt){
	
	Puntaje aux;
	strcpy(aux.nombre,new_nom.c_str()); aux.puntos = new_punt;
	
	ranking_p.push_back(aux);
	
/*con reverse (rbegin y rend) ordena el vector de forma decreciente, con los puntajes mas altos al principio y los mas 
bajos al final. Despues uso funcion comparar para ver si el nuevo puntaje superó a alguno de los mejores*/
	sort(ranking_p.rbegin(),ranking_p.rend(),comparar);
	
	ranking_p.resize(min(5,(int)ranking_p.size()));//cambio el tamaño por el minimo nro entre 5 y el tamaño original.
}

//funcion encargada de actualizar el archivo
void TablaPuntajes::Guardar(){
	ofstream refresh("mejores_puntajes.dat",ios::binary|ios::trunc);
	for(size_t i=0;i<ranking_p.size();i++){
		refresh.write(ranking_p[i].nombre,sizeof(ranking_p[i].nombre));
		refresh.write(reinterpret_cast<char*>(&ranking_p[i].puntos),sizeof(int));
	}
	refresh.close();
}
void TablaPuntajes::Mostrar(){
	for(int i=0;i<ranking_p.size();i++) { 
		cout << ranking_p[i].nombre << " " << ranking_p[i].puntos << "\n";
	}
}
