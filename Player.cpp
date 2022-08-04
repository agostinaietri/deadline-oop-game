#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : m_pos(270,304){
	m_t.loadFromFile("walk.png");
	m_s.setTexture(m_t);
	m_s.scale(0.5,0.5);
}
//Player::Player(String m_img) : Objeto("shadow.png"), m_pos(-200,48) {
//	m_s.setScale(2.0,2.0);
//};

bool Player::colisionaCon(ObjetoSinTex &obj){
	auto bb_otro = obj.GetBB(); 
	auto bb_player = this->GetBB();
	
	bb_otro.height-=10; // se "achica" la altura del rect de player
	
	bb_player.left+=20;  //se "alarga" la coordenada del lado izquierdo
	bb_player.height-=20;// se achica la altura
	bb_player.width-=50; // se achica el ancho 
	
	return bb_player.intersects(bb_otro);
}
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
