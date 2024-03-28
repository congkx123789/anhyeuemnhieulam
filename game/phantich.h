#pragma once
#include"Game.h"
class phantich
{
public:
	void checkDOWN(char down);
	void checkUP(char up);
	bool find1(char key);

	bool return_jumb() { return jumb; }

	void SetJumb(Uint32 x, Uint32 y) {
		if (x == y)speedg = 1;
		else speedg = 0;
	}
	bool checkSDL(SDL_Rect a, SDL_Rect b) {
		if (a.x != b.x)return 0;
		if (a.y != b.y)return 0;
		return 1;
	}
	bool Getspeedx() { return speedx; }

	bool Getspeedg() { return speedg; }

	void checkRECT(SDL_Rect old, SDL_Rect check);

	char checkinput();
	
	//char findKEY();

private:
	bool jumb = 0;
	bool speedx = 0;
	bool speedg = 0;
	int oldg = 0;

	bool chieu = 1;
	char logic = '+';
};

