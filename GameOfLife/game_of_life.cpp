#include "game_of_life.h"



bool game_of_life::rand50()
{
	return rand() & 1;
}

bool game_of_life::slucajna_vrijednost()
{

	return rand50() & rand50();
}

int game_of_life::brojSusjeda(int l, int k)
{
	counter = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			counter += _generacija[l + i][k + j];
		}
	}
	counter -= _generacija[l][k];
	return counter;
}



game_of_life::game_of_life()
{
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	

	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if ((_generacija[i][j] == 1) && (brojSusjeda(i, j) < 2))_sljedeca_generacija[i][j] = 0;

			else if ((_generacija[i][j] == 1) && (brojSusjeda(i, j) > 3))_sljedeca_generacija[i][j] = 0;

			else if ((_generacija[i][j] == 0) && (brojSusjeda(i, j) == 3))_sljedeca_generacija[i][j] = 1;

			else _sljedeca_generacija[i][j] = _generacija[i][j];
			
		}
	}

	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}

	

}

void game_of_life::iscrtaj()
{
	system("CLS");
	for (unsigned i = 0; i < REDAKA; i++)
	{
		for (unsigned j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 1)cout << "*";
			else cout << "_";
		}
		cout << endl;
	}
}
