#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class game_of_life {
private:
	bool rand50();
	unsigned int counter;
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	int brojSusjeda(int i,int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
