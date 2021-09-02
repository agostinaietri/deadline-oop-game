#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : Objeto ("zed-sprite.png") , m_pos(270,324){
	m_s.scale(0.5,0.5);
}


void Player::Update ( ) {

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

