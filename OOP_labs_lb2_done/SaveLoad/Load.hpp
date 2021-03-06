#pragma once
#include "../GameControl/PlayGroundStruct.hpp"
#include "../Interface/MyInterface.hpp"
#include <regex.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Load{
	private:
		ifstream* m_file;
	private:
		bool checkMatrix(char** matrix, int x, int y);
		bool checkPlayer(int x, int y, int health, int damage, int lev, int width, int height);
		bool checkEnemy(int num, int x, int y, int health, int damage, int lev, int width, int height);
		int calcSpaces(string& st);
		bool checkData(string& data, const char* pattern);
	public:
		Load(const char* filename);
		~Load();
		int makeLoad(PlayGround& field);
};
