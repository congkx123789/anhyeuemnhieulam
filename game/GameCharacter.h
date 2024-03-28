#pragma once
#include"Game.h"
class GameCharacter 
{
public:

	GameCharacter(const char* tittleofsheet, SDL_Renderer* renderer, int x, int y);

	void update(char key,bool check);
	
	void check();

	void resetSPE(SDL_Rect old, SDL_Rect check);

	void SetADD(SDL_Rect ok) { Address = ok; }

	void GetTIME(double TIME) { TIMEnow = TIME; }

	void GetTIMEold() { TIMEold = TIMEnow; }

	SDL_Rect GetADD() { return Address; }

	void render1();
	 
private:

	double TIMEnow = 0;
	
	double TIMEold = 0;

	

	SDL_Rect sizePIC;

	SDL_Rect Address;

	SDL_Renderer* render;

};