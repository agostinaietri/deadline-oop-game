#include "GameOver.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Menu.h"


GameOver::GameOver(int new_score) {
	m_font.loadFromFile("FreePixel.ttf");
	m_tex1.setFont(m_font);
	m_tex2.setFont(m_font);
	m_tex_pidedatos.setFont(m_font);
	
	m_tex1.setString("game over!");
	m_tex1.setPosition(180,70);
	m_tex1.setCharacterSize(80);
	
	m_tex2.setString("press Backspace to return to the menu screen");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(150 ,260);
	m_tex2.setCharacterSize(20);
	
	game_over_music.openFromFile("game_over_music.ogg");
	
	game_over_music.setVolume(10);
	game_over_music.play();

	// Los datos del último Player.
	string new_name; 
	cin>> new_name;	/// despues de ver lo de Game, lo borro.
	// se va a usar en otra funcion, junto con puntaje_g.
	
	/// Seteo el texto para pedir el nombre
	m_tex_pidedatos.setString("enter your name: ");
	m_tex_pidedatos.setFillColor({150,150,150});
	m_tex_pidedatos.setPosition(150 ,100);
	m_tex_pidedatos.setCharacterSize(20);
	
	
	/// Abro el archivo de los puntajes, agrego el nuevo puntaje al vector, reacomodo el ranking/lo dejo igual y con eso actualizo el archivo.
	
	this->Archivo();
	
	this->SetearPuntajes();
	
	this->Ingresar(new_name,new_score); //uso el nombre ingresado x teclado y el puntaje de la ultima partida.
	
	this->Actualizar();
}
void GameOver::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex1);
	Window2.draw(m_tex2);
	Window2.draw(m_tex_pidedatos); //el txt "ingrese su nombre"
	
	// para mostrar el ranking, de la forma: "nombre    puntos".
	for(int i=0;i<textos_players.size();i++) { 
		Window2.draw(textos_players[i]);
	}
	
	Window2.display();
}
void GameOver::Update (Game &gamee ) {
	
	unsigned char r = rand();
	unsigned char g = rand();
	unsigned char b = rand();
	
	m_tex1.setFillColor({r,g,b});
	
	if (Keyboard::isKeyPressed(Keyboard::Key::BackSpace)){
		gamee.SetScene(new Menu());
		game_over_music.stop();
	}
	
}
void GameOver::Archivo(){
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

void GameOver::SetearPuntajes(){
	/// Setea los textos de los puntajes: c/jugador dentro del ranking se coloca juntado los atributos de cada Puntaje como un string.
	for(size_t i=0;i<ranking_p.size();i++) { 
		string nom_txt = ranking_p[i].nombre + " " + to_string(ranking_p[i].puntos); // string q se le asigna a cada elemento texto.
		Text player;
		player.setFont(m_font);
		player.setString(nom_txt);
		player.setFillColor({150,150,150});
		player.setPosition(150,(130+10));//va sumando +10 al eje 'y' asi se acomodan uno abajo del otro. 
		player.setCharacterSize(40);
			textos_players[i] = player; // el vector<Text> se carga.
	}
	
}
//


///compara los puntajes para cambiar la posicion de los mismos.
int comparar(const Puntaje &a, const Puntaje &b){
	return a.puntos>b.puntos; 
}
void GameOver::Ingresar(string new_name, int new_score){
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
	
	ranking_p.resize(5);;//cambio el tamaño a 5 y descarta al 6to.
	//ranking_p.resize(min(5,(int)ranking_p.size()));//cambio el tamaño por el minimo nro entre 5 y el tamaño original.
}
void GameOver::Actualizar(){
	/// Actualización del archivo
	ofstream refresh("mejores_puntajes.txt",ios::trunc);
	for(size_t i=0;i<ranking_p.size();i++){
		refresh << "\n" << ranking_p[i].nombre << " " << ranking_p[i].puntos << endl ;
	}
	refresh.close();	
}