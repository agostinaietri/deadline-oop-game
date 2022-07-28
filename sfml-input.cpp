#include <SFML/Graphics.hpp>
#include "InputBox.h" // este es el header de la clase, adentro tiene un pequeña ayuda
using namespace std;
using namespace sf;


int main(int argc, char *argv[]){
	
	// crea una ventana
	RenderWindow w(VideoMode(640,480),"Ejemplo de SFML");
	
	// cargar una fuente para los textos
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	// crear un texto comun
	sf::Text text_comun("Ingrese una palabra (hasta 10 letras):",font);
	text_comun.setCharacterSize(25);
	text_comun.setColor(sf::Color::Blue);
	text_comun.setPosition(100,20);
	
	// crear otro texto comun
	string palabras="Palabras ingresadas:";
	sf::Text text_palabras(palabras,font);
	text_palabras.setCharacterSize(25);
	text_palabras.setColor(sf::Color::Red);
	text_palabras.setPosition(100,100);
	
	// texto que ingresa el usuario
	InputText text_entrada(font,30,sf::Color::Black);
	text_entrada.setPosition(120,50);
	text_entrada.setMaxChars(10); // no mas de 10 caracteres
	text_entrada.setSingleWord(true); // no permitir ingresar espacios, para que sea solo una palabra
		
	// bucle principal
	while(w.isOpen()) {
		
		// procesar eventos
		Event e;
		while(w.pollEvent(e)) {
				if(e.type == Event::Closed)
					w.close();	
				else if (e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return) { // si apretó enter, se toma la palabra y se la agrega a la lista
					string string_ingresado = text_entrada.getValue(); // obtener la palabra que se ingresó
					palabras += "\n\t"; palabras += string_ingresado;
					text_palabras.setString(palabras);
					text_entrada.reset(); // reiniciar la entrada para tomar otra palabra
				} else text_entrada.processEvent(e); // para que el texto tome las teclas que pulsamos
		}
		
		// dibujar
		w.clear(Color(255,255,255,255));
		text_entrada.update(); // para que el texto se dibuje correctamente (hay que hacer esta llamada despues de processEvent y antes del draw)
		w.draw(text_comun);
		w.draw(text_entrada);
		w.draw(text_palabras);
		w.display();
	}
	return 0;
}

