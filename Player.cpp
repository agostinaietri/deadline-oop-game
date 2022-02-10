#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : Objeto ("walk.png") , m_pos(270,304){
	m_s.scale(0.5,0.5);
}

//Player::Player(String m_img) : Objeto("shadow.png"), m_pos(-200,48) {
//	m_s.setScale(2.0,2.0);
//};

void Player::Update ( ) {

	auto tex_sz = m_t.getSize();
	m_s.setTextureRect({(m_num_frame/10)*int(tex_sz.x)/4,0,int(tex_sz.x)/4,int(tex_sz.y)});
	m_num_frame = (m_num_frame+1)%40;
	
	
	
	m_speed.y += 0.15;
	m_pos += m_speed;
	
	if(m_pos.y>=304){
		m_speed.y = 0;
		m_pos.y = 304;
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			m_speed.y = -6;
		}
	}
	
	m_s.setPosition(m_pos);
}

