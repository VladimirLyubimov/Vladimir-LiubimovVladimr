#include "MyPlayer.hpp"

MyPlayer::MyPlayer(int x, int y, int health, int damage , int level, int exp, bool collected) : MyHuman(x, y, health, damage, level), m_exp(exp), m_collected(collected), m_exit(false){
};

void MyPlayer::addExp(int exp){
	m_exp += exp;
};

void MyPlayer::setCollected(){
	m_collected =  true;
};

void MyPlayer::levelup(){
	if(m_exp >= 100){
		MyHuman::levelup();
		addExp(-100);
	}
};

char MyPlayer::print(){
	return 'H';
};

bool MyPlayer::getCoollected(){
	return m_collected; 
};

void MyPlayer::setExit(){
	if (m_collected)
		m_exit =  true;
};

bool MyPlayer::getExit(){
	return m_exit;
};

int MyPlayer::getExp(){
	return m_exp;
}

std::string MyPlayer::getLogData(){
	std::string data("Player position is (");
	int x = 0;
	int y = 0;
	this->getCoord(x,y);
	data += std::to_string(x) + ";" + std::to_string(y) + "). ";
	data += "Health = " + std::to_string(this->getHealth()) + ". ";
	data += "Level = " + std::to_string(this->getLevel()) + ". ";
	data += "Experience = " + std::to_string(this->getExp()) + ".";
	data += "Damage = " + std::to_string(this->getDamage()) + ".";
	
	if(this->m_inter){
		data += " Interaction has been completed!";
		m_inter = false;
	}
	if(this->m_kill){
		data += " Target has been destroyed!";
		m_kill = false;
	}
	if(this->getHealth() <= 0)
		data += " Health isn't below 0. Game over!";
	data += "\n";
	return data;	
}

LogInterface& operator <<(LogInterface& log, MyPlayer* player){
	log.writeLog(player->getLogData());
	return log;
}
