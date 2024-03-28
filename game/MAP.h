#pragma once
#include"Game.h"
class MAP
{
public:

	MAP(const char* tittle, SDL_Renderer* render, SDL_Rect screen);

	void RenderCP();

	void GetScreen(SDL_Rect screen);

	SDL_Rect coll(SDL_Rect check);

	void update();

	void GetOLD(SDL_Rect OLD) { old = OLD; }

private:
	SDL_Rect Screen;
	SDL_Renderer* renderer;
	SDL_Texture** wall;
	SDL_Rect old;

};

