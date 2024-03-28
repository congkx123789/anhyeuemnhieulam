#include "MAP.h"

function1 func1;

map<int, vector<SDL_Rect>> mapGame;

map<int, vector<SDL_Rect>> mapG;

SDL_Rect add;

MAP::MAP(const char* tittle, SDL_Renderer* render, SDL_Rect screen)
{
	add.w = 32;
	add.h = 32;
	renderer = render;
	Screen = screen;
	ifstream readfile(tittle);
	int n;// so loai tuong
	readfile >> n;
	wall = new SDL_Texture * [n];
	string s;
	for (int i = 0; i < n; i++) {

		readfile >> s;// tuong
		cout << s << endl;
		wall[i] = func1.Manager_Texture(s.c_str(), renderer);
	}

	int a;

	for (int i = 0; i < n; i++) {
		readfile >> a;
		cout << a << endl;
		for (int j = 0; j < a; j++) {

			readfile >> add.x >> add.y;

			mapGame[i].push_back(add);
		}

	}
	readfile.close();
}//0

void MAP::RenderCP()
{
	int a = 0;
	for (auto i : mapG) {
		for (int j = 0; j < i.second.size(); j++) {
			SDL_RenderCopy(renderer, wall[a], NULL, &i.second[j]);
		}
		a++;
	}
	//mapG.clear();
}//3

void MAP::GetScreen(SDL_Rect screen)
{
	Screen = screen;
}

SDL_Rect MAP::coll(SDL_Rect check)
{
	SDL_Rect a1 = { min(check.x,old.x),min(check.y,old.y),check.w + abs(check.x - old.x),check.h + abs(check.y - old.y) };
	vector<SDL_Rect> ok;
	for (auto i : mapG) {
		for (int j = 0; j < i.second.size(); j++) {
			if (func1.checkSDL1(a1, i.second[j]) == 0)
				ok.push_back(i.second[j]);
		}
	}

	a1 = check;
	func1.setDouble_AndOld(check.x, check.y, old);
	a1.x = func1.reDoubleF();
	a1.y = func1.reDoubleS();
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}

	func1.lamtron();
	a1.x = func1.reDoubleF();
	a1.y = func1.reDoubleS();
	if (a1.x != old.x || a1.y != old.y) {
		if (a1.x < 0)a1.x = 0;
		old = a1;
		
		return a1;
	}
	func1.setDouble_AndOld(old.x, check.y, old);

	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}
	func1.lamtron();
	a1.y = func1.reDoubleS();
	if (a1.y != old.y) {
		if (a1.x < 0)a1.x = 0;
		old = a1;
		return a1;
	}

	func1.setDouble_AndOld(check.x, old.y, old);
	for (int i = 0; i < ok.size(); i++) {
		for (int j = 0; j < ok.size(); j++) {
			if (func1.checkDouble(check.w, check.h, ok[j]) == 0) {
				func1.answer1(ok[j], check.w, check.h);
			}
		}
	}
	
	func1.lamtron();
	a1.x = func1.reDoubleF();
	if (a1.x < 0)a1.x = 0;
	old = a1;
	return a1;
}//2

void MAP::update()
{
	add.w = 32;
	add.h = 32;
	int a = 0;
	for (auto i : mapGame) {
		add.w = i.second[0].w;
		add.h = i.second[0].h;
		for (int j = 0; j < i.second.size(); j++) {
			cout << i.second.size() << endl;
			if (i.second[j].x + 32 > Screen.x && i.second[j].x < Screen.x + Screen.w)
			{
				add.x = i.second[j].x - Screen.x;
				add.y = i.second[j].y;
				mapG[a].push_back(add);
			}
		}
		a++;
	}
}
