//背单词策略基类
//作为Wordreciting类的友元

#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy
{
	friend class Wordreciting; //便于在Wordreciting中直接访问Stratrgy

private:
	static int minProportion;
	static int maxProportion;
	static int minDailyNumber;
	static int maxDailyNumber;

    static int defaultProportion;
    static int defaultDailyNumber;

private:
	int newProportion; //每日新词的比例，剩下的旧词根据权值（数量+难度）随机
	int dailyNumber; //每日单词的数量
	bool selectRandom; //单词挑选为顺序（false/0）或者随机（true/1）

public:
	Strategy();
	~Strategy();

	void setProportion(int);
	void setDailyNumber(int);
	void setRandom(bool);

	int getProportion() const {return newProportion;}
	int getDailyNumber() const {return dailyNumber;}
	int getRandom() const {return selectRandom;}

	static int getMinProportion() {return minProportion;}
	static int getMaxProportion() {return maxProportion;}
	static int getMinDailyNumber() {return minDailyNumber;}
	static int getMaxDailyNumber() {return maxDailyNumber;}

    static int getDefaultProportion() {return defaultProportion;}
    static int getDefaultDailyNumber() {return defaultDailyNumber;}
};

#endif
