#ifndef MANEJOARCHIVO_H
#define MANEJOARCHIVO_H
#include <vector>
#include <string>
using namespace std;

struct Puntaje{
	string nombre;
	int puntos;
};

class ManejoArchivo {
public:
	ManejoArchivo();
	size_t PedirTamanio();
	string PedirElemento(int x);
	void Ingresar(string new_name, int new_score);
	//void Actualizar();
private:
	vector<Puntaje>ranking_p;
};

#endif

