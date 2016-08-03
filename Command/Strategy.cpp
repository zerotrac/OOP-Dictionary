#include "Strategy.h"

int Strategy::minProportion = 10;
int Strategy::maxProportion = 90;
int Strategy::minDailyNumber = 20;
int Strategy::maxDailyNumber = 500;

int Strategy::defaultProportion = 20;
int Strategy::defaultDailyNumber = 100;

Strategy::Strategy()
{
	newProportion = minProportion;
	dailyNumber = minDailyNumber;
	selectRandom = false;
}

Strategy::~Strategy()
{

}

void Strategy::setProportion(int x)
{
	if (x >= minProportion && x <= maxProportion) newProportion = x;
}

void Strategy::setDailyNumber(int x)
{
	if (x >= minDailyNumber && x <= maxDailyNumber) dailyNumber = x;
}

void Strategy::setRandom(bool b)
{
	selectRandom = b;
}
