//背单词基类

#ifndef WORDRECITING_H
#define WORDRECITING_H

#include "Wordlist.h"
#include "Strategy.h"
#include "DailyWordreciting.h"

class Wordreciting
{
private:
	Strategy *strategy; //背单词的策略
	
	bool isStart; //是否执行过start()
	Wordlist *ordered; //顺序
	Wordlist *random; //随机
	Wordlist *wordlist; //开始背单词时定下的顺序，在背单词中途不得更改

	DailyWordreciting *dailywordreciting; //每日背的单词
	Word *curWord; //当前背的单词
	int curWordGroup; //当前背的单词属于的组
	int regWordGroup; //当前背的单词调整之后的组

public:
	Wordreciting(Wordlist *); //默认构造函数中必须包含一个单词列表（这个单词列表是顺序的）
	~Wordreciting();

	bool ifStart() const {return isStart;} //这本单词书是否背过
	void start(); //开始背一本新的单词书，这之后strategy->selectRandom()将不可更改
	void clear(); //不再背这本单词书

	void startDailyMission(); //开始今日的背单词任务

    //结束（或者放弃）今日的背单词任务（反正就是删掉DailyWordreciting *，记住之后output一下用户记录）
    void abandonDailyMission() {delete dailywordreciting;}

	void toNext(); //跳转到下一个单词
    Word *getCurWord() const {return curWord;} //返回当前这个单词
	void giveAnswer(int); //给出用户对这个单词的答案（0/1）表示（不会/会）
	void kill(); //这个单词太简单，用户选择“斩”掉
	void regret(); //用户反悔了他给出的“会”答案

    //获取当前（难词/0）（生词/1）（熟词/2）的数量
    int getDailyCount(int);

	bool isCompleted() const; //单词是否全部背完
	bool isDailyCompleted() const; //今日单词是否全部背完

	//这些应该都用不到
	int size() const;
	Word *getWord(int) const;
	void setStart();
	int getPercent() const;

	//对Strategy成员函数的封装
	void setProportion(int);
	void setDailyNumber(int);
	void setRandom(bool);

	int getProportion() const {return strategy->getProportion();}
	int getDailyNumber() const {return strategy->getDailyNumber();}
	int getRandom() const {return strategy->getRandom();}

	int getMinProportion() const {return strategy->getMinProportion();}
	int getMaxProportion() const {return strategy->getMaxProportion();}
	int getMinDailyNumber() const {return strategy->getMinDailyNumber();}
	int getMaxDailyNumber() const {return strategy->getMaxDailyNumber();}
};

#endif
