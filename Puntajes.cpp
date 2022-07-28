#include "Puntajes.h"
#include "Menu.h"

Puntajes::Puntajes(string new_name,int new_score) {
	m_font.loadFromFile("FreePixel.ttf");
	
	/// aca la clase ManejoArchivo se encarga de tener guardados los puntajes mas altos.
	m_archivo.Ingresar(new_name, new_score); // el ultimo jugador q ingresó su nombre es agregado al vector de puntajes junto con los puntos q hizo.
	
	this->SetearPuntajes();
}
/*Puntajes::Puntajes(){ // ctor en caso que solo se quieran ver los mejores puntajes
	this->SetearPuntajes();
}*/
//

void Puntajes::SetearPuntajes(){
	/// Setea los textos de los puntajes: c/jugador dentro del ranking se coloca juntando los atributos de cada Puntaje como un string.
	
	for(size_t i=0;i<5;i++) { 
		string nom_txt = m_archivo.PedirElemento(i);
		Text player;
		player.setFont(m_font);
		player.setString(nom_txt);
		player.setFillColor({150,150,150});
		player.setPosition(150,(130+10*i));//va sumando +10 al eje 'y' asi se acomodan uno abajo del otro. 
		player.setCharacterSize(40);
		textos_players.push_back(player); 
	}	
	
}
//
void Puntajes::Draw (RenderWindow & Window) {
	Window.clear({0,0,0});
	
	// para mostrar el ranking de la forma: "nombre: ___   puntos:__".
	for(int i=0;i<5;i++) { 
		Window.draw(textos_players[i]);
	}
}

void Puntajes::Update (Game & gamee) {
	if(Keyboard::isKeyPressed(Keyboard::Escape)){ // Esc para volver al Menu.
		gamee.SetScene(new Menu());
	}
}

