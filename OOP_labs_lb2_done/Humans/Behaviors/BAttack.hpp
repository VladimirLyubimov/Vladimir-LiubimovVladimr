#pragma once
#include "Behavior.hpp"

class BAttack: public Behavior{
	public:
		virtual void Action(MyHuman* attacker, MyHuman* aim);
};
