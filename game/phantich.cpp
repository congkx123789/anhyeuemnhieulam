#include "phantich.h"

map<char, bool> input;

bool jumb_animation = 0;
Uint32 test = 0;
void phantich::checkDOWN(char down)
{
	if (down != 'k') {
		if (down == 'a') {
			chieu = 0;
			input[down] = 1;
			if (input['d']) {
				speedx = 1;
				input.erase('d');
			}
		}
		else if (down == 'd') {
			chieu = 1;
			input[down] = 1;
			if (input['a']) {
				speedx = 1;
				input.erase('a');
			}
		}
	}
	else if (jumb == 1) {
		test = SDL_GetTicks();
		input[down] = 1;
		jumb = 0;
	}

}

void phantich::checkUP(char up)
{
	input.erase(up);
}

bool phantich::find1(char key)
{
	return input[key];
}


void phantich::checkRECT(SDL_Rect old, SDL_Rect check)
{
	if (old.x != check.x) {
		speedx = 1;

	}
	else speedx = 0;
	if (old.y != check.y && check.y == oldg) {
		if (check.y < old.y)jumb = 1;
		speedg = 1;

	}
	else {
		speedg = 0;
	}
	oldg = check.y;
}

char phantich::checkinput()
{
	if (SDL_GetTicks()- test < 500)jumb_animation = 1;
	else jumb_animation = 0;
	if (jumb_animation && chieu)return'k';
	else if (jumb_animation && chieu == 0)return '!';
	else if (input['a'])return'a';
	else if (input['d'])return 'd';
	else if (chieu) return '+';
	else return '-';
}

//char phantich::findKEY()
//{
//	if(input = )
//}

