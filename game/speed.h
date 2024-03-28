#pragma once
#include"Game.h"
class speed
{
public:

	int runright(double TIMEnow, double TIMEold);

	int down(double TIMEnow, double TIMEold);

	int jumb();
	
	//void GETtimeNOW(double time) {TIMEnow = time;}

	//void Gettimeold() { TIMEold = TIMEnow; }

	void resetG() { SpeedG = 0; }

	void resetX() { SpeedX = 0; }

private:
	//double TIMEold = 0;

	//double TIMEnow = 0;

	double SpeedG = 0;

	double SpeedX = 0;
	
	double run = 0;

	double g = 2000;

	double g2 = 10000;

	double g1 = -200000;
};

