#include "Cat.h"
#include <SFML/Window/Keyboard.hpp>

Cat::Cat() : Objeto ("gatito 4.png") , m_pos(270,324){
	m_s.scale(0.5,0.5);
}


void Cat::Update ( ) {
	
//	if(Keyboard::isKeyPressed(Keyboard::Key::Left)){
//		m_speed.x = -3;
//	}else{
//		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
//			m_speed.x = +3;
//		}else{
//			m_speed.x = 0;
//		}
//	}
//	
	m_speed.y += 0.15;
	m_pos += m_speed;
	
	if(m_pos.y>=324){
		m_speed.y = 0;
		m_pos.y = 324;
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			m_speed.y = -6;
		}
	}
	
	m_s.setPosition(m_pos);
}

