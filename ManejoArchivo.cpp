#include "ManejoArchivo.h"
#include <fstream>
#include <algorithm>
using namespace std;

ManejoArchivo::ManejoArchivo() {
	///Carga del archivo de texto los puntajes del juego al vector<Puntaje>.
	
	//metodo open
	ifstream cargar("mejores_puntajes.txt");
	if( !cargar.is_open() ){
		
		ofstream cargar_arch("mejores_puntajes.txt",ios::trunc);
		Puntaje auxi; auxi.nombre = "xxx"; auxi.puntos = 0;
		for(int i=0;i<5;i++) { 
			cargar_arch << auxi.nombre <<" " << auxi.puntos << endl;
		}	
		cargar_arch.close();
		ifstream cargar("mejores_puntajes.txt");
	}
	
	// leo desde el archivo los nombres y puntos q ya estan.
	Puntaje aux;
	while(cargar >> aux.nombre >> aux.puntos ){ 
		ranking_p.push_back(aux);
	}
	cargar.close();
}
//


//
string ManejoArchivo::PedirElemento(int x){
	string ss = ranking_p[x].nombre + " " + to_string(ranking_p[x].puntos);
	return ss;
}

size_t ManejoArchivo::PedirTamanio(){
	return ranking_p.size();
}

///compara los puntajes para cambiar la posicion de los mismos.
static int comparar(const Puntaje &a, const Puntaje &b){
	return a.puntos>b.puntos; 
}

void ManejoArchivo::Ingresar(string new_name, int new_score){ 
	/// Ingreso el nuevo puntaje y acomodo el ranking.
	
	//armo un Puntaje auxiliar para que cargue el jugador que acaba de terminar la partida.
	Puntaje aux;
	aux.nombre = new_name; 
	aux.puntos = new_score;
	
	ranking_p.push_back(aux);
	
	/*con reverse (rbegin y rend) ordena el vector de forma decreciente, con los puntajes mas altos al principio y los mas 
	bajos al final usando como criterio los puntos del vector de Puntajes (mediante la funcion comparar)
	para ver si el nuevo puntaje superó a alguno de los mejores existentes.*/
	sort(ranking_p.rbegin(),ranking_p.rend(),comparar);
	
	ranking_p.resize(5);//cambio el tamaño a 5 y descarto al 6to.
	//ranking_p.resize(min(5,(int)ranking_p.size()));//cambio el tamaño por el minimo nro entre 5 y el tamaño original.
	
	ofstream refresh("mejores_puntajes.txt",ios::trunc);
	for(size_t i=0;i<ranking_p.size();i++){
		refresh << ranking_p[i].nombre << " " << ranking_p[i].puntos << endl ;
	}
}
	
