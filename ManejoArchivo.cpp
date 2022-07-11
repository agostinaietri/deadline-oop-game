#include "ManejoArchivo.h"
#include <fstream>
#include <algorithm>
using namespace std;

ManejoArchivo::ManejoArchivo(){
	///Carga del archivo de texto los puntajes del juego al vector<Puntaje>.
	
	//metodo open
	ifstream cargar("mejores_puntajes.txt");
	if( !cargar.is_open() ){	
		Puntaje auxi; auxi.nombre = "xxx"; auxi.puntos = 0;/// buscar otra accion por si no lo abre
		cargar >> auxi.nombre >> auxi.puntos;
	}
	
// leo desde el archivo los nombres y puntos q ya estan.
	Puntaje aux;
	while(cargar >> aux.nombre >> aux.puntos ){ 
		ranking_p.push_back(aux);
	}
	cargar.close();
}
//

///compara los puntajes para cambiar la posicion de los mismos.
int comparar(const Puntaje &a, const Puntaje &b){
	return a.puntos>b.puntos; 
}
//

string ManejoArchivo::PedirElemento(int x){
	string ss = ranking_p[x].nombre + " " + to_string(ranking_p[x].puntos);
	return ss;
}
//

size_t ManejoArchivo::PedirTamanio(){
	return ranking_p.size();
}
//


void ManejoArchivo::Ingresar(string new_name, int new_score){
	/// Ingreso el nuevo puntaje y acomodo el ranking.
	
	//armo un Puntaje auxiliar para que cargue el jugador que acaba de terminar la partida.
	Puntaje aux;
	aux.nombre = new_name; 
	aux.puntos = new_score; // uso el puntaje que le asigne del q recibió por constructor.
	
	ranking_p.push_back(aux);
	
	/*con reverse (rbegin y rend) ordena el vector de forma decreciente, con los puntajes mas altos al principio y los mas 
	bajos al final usando como criterio los puntos del vctor de Puntajes (mediante la funcion comparar)
	para ver si el nuevo puntaje superó a alguno de los mejores existentes.*/
	sort(ranking_p.rbegin(),ranking_p.rend(),comparar);
	
	ranking_p.resize(5);//cambio el tamaño a 5 y descarta al 6to.
}
//

void ManejoArchivo::Actualizar(){
	/// Actualización del archivo
	ofstream refresh("mejores_puntajes.txt",ios::trunc);
	for(size_t i=0;i<ranking_p.size();i++){
		refresh << "\n" << ranking_p[i].nombre << " " << ranking_p[i].puntos << endl ;
	}
	refresh.close();	
}