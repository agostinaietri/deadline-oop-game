#include "GameOver.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Menu.h"
#include <iostream>
#include <SFML/Window/Event.hpp>


GameOver::GameOver(int new_score) {
	m_new_score = new_score; // se guarda el npunt de la ult partida para usarlo dsps.
	
	m_font.loadFromFile("FreePixel.ttf");
	m_tex1.setFont(m_font);
	m_tex2.setFont(m_font);
	m_tex_pidenom.setFont(m_font);
	
	m_tex1.setString("game over!");
	m_tex1.setPosition(180,70); // estaba en m_tex1.setPosition(180,140), quedó mas arriba para darle espacio al ranking.
	m_tex1.setCharacterSize(80);
	
	m_tex2.setString("press Backspace to return to the menu screen");
	m_tex2.setFillColor({150,150,150});
	m_tex2.setPosition(150 ,260);
	m_tex2.setCharacterSize(20);
	
	game_over_music.openFromFile("game_over_music.ogg");
	game_over_music.setVolume(10);
	game_over_music.play();
	
	/// Seteo el texto para pedir el nombre
	m_tex_pidedatos.setString("enter your name: ");
	m_tex_pidedatos.setFillColor({150,150,150});
	m_tex_pidedatos.setPosition(150 ,100);
	m_tex_pidedatos.setCharacterSize(20);
}
//

void GameOver::Draw (RenderWindow &Window2) {
	Window2.clear({0,0,0});
	Window2.draw(m_tex1);
	Window2.draw(m_tex2);
	Window2.draw(m_tex_pidenom); //el txt "ingrese su nombre"
	
	text_entrada.update();// para que el texto se dibuje correctamente (hay que llamar a update antes de pasarselo a draw)
	Window2.draw(text_entrada); // el q se ingresa x teclado
	
	// para mostrar el ranking, de la forma: "nombre___   puntos__".
	for(int i=0;i<ranking_p.size();i++) { 
		Window2.draw(textos_players[i]);
	}

	Window2.display();
}
//


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
//


void GameOver::SetearPuntajes(){
	/// Setea los textos de los puntajes: c/jugador dentro del ranking se coloca juntado los atributos de cada Puntaje como un string.
	for(size_t i=0;i<m_archivo.PedirTamanio();i++) { 
		string nom_txt = m_archivo.PedirElemento(i);
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

void GameOver::ProcessEvent(Event &e){
	
	// texto que ingresa el usuario
	// aca tengo que llamar a la clase de novara.
	text_entrada.setPosition(150,130);
	text_entrada.setMaxChars(10); // no mas de 10 caracteres
	text_entrada.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una 

	text_entrada.processEvent(e);
	
	string new_name = text_entrada.getValue(); // obtener la palabra que se ingresó
	
	/// aca se lleva a cabo la parte de manejo de archivo con la clase ManejoArchivo para tener guardados los puntajes mas altos.
	m_archivo();
	
	m_archivo.Ingresar(new_name, m_new_score); // el ultimo jugador q ingresó su nombre es agregado al vector de puntajes junto con los puntos q hizo.
	
	this->SetearPuntajes();
	
	m_archivo.Actualizar();
}