#pragma once
#include "MyObject.hpp"

class MyBonus : public MyObject{
	public:
		MyBonus();
		virtual bool operator +=(MyPlayer* player);
		virtual std::string getLogData();
		virtual ~MyBonus();
};
