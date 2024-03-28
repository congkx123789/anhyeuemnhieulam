#include "GameCharacter.h"

speed SpeedOfmain;
map<char, pair <int, SDL_Texture**>>CharacterTex;
phantich input;


void GameCharacter::check()
{
	if (input.find1('a')) {
		Address.x -= SpeedOfmain.runright(TIMEnow, TIMEold);
		cout << "a" << endl;
	}
	if (input.find1('d')) {
		Address.x += SpeedOfmain.runright(TIMEnow, TIMEold);
		cout << "d" << endl;
	}
	if (input.find1('k')) {
		Address.y += SpeedOfmain.jumb();
		cout << "k" << endl;
	}
	input.checkUP('k');
	Address.y += SpeedOfmain.down(TIMEnow, TIMEold);
}

void GameCharacter::resetSPE(SDL_Rect old,SDL_Rect check)
{
	input.checkRECT(old, check);
	if (input.find1('d') == 0 && input.find1('a') == 0) 
		 SpeedOfmain.resetX();
	Address = check;

	if (input.Getspeedx())SpeedOfmain.resetX();
	if (input.Getspeedg())SpeedOfmain.resetG();

}

void GameCharacter::render1()
{
	char key = input.checkinput();
	SDL_RenderCopy(render, CharacterTex[key].second[int(TIMEnow * double(8.33)) % CharacterTex[key].first], &sizePIC, &Address);
}

void GameCharacter::update(char key, bool check)
{
	//cout << key << endl;
	if (check)
		input.checkDOWN(key);
	else
		input.checkUP(key);
	if (input.Getspeedx())SpeedOfmain.resetX();
	if (input.Getspeedg())SpeedOfmain.resetG();
}

GameCharacter::GameCharacter(const char* file, SDL_Renderer* renderer, int x, int y)
{
	render = renderer;
	int n, n1;
	string a, b;
	char key;
	function1 func;

	ifstream readfile(file);
	readfile >> n;

	for (int j = 0; j < n; j++) {

		readfile >> a;
		readfile >> key;
		ifstream readmyfile(a.c_str());
		readmyfile >> n1;

		CharacterTex[key].second = new SDL_Texture * [n1];
		CharacterTex[key].first = n1;

		for (int i = 0; i < n1; i++) {
			readmyfile >> b;

			CharacterTex[key].second[i] = func.Manager_Texture(b.c_str(), renderer);

		}
		readmyfile.close();
	}
	readfile.close();
	Address = { 0,0,37,50 };
	sizePIC = { 7,6,28,30 };
}
