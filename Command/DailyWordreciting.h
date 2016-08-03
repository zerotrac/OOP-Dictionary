//每日背单词任务基类

#ifndef DAILYWORDRECITING_H
#define DAILYWORDRECITING_H

#include <queue>
#include "Word.h"

class DailyWordreciting
{
	friend class Wordreciting;

private:
	//每日背单词分为（不会的/未背的/背会的）三种
	//原来设定的用（freshWordlist/newWordlist/learnedWordlist）表示
	//但是不方便管理
	//故改成size=3的数组，用(0/1/2)代替上面的(f/n/l)
	std::queue <Word*> words[3];
	int size[3]; //每个queue的长度

public:
	DailyWordreciting();
	~DailyWordreciting();

	void push(Word*, int); //向words[int]里放入一个单词
	void pop(int); //words[int]里释放一个单词
	void clear(); //清空所有单词

	bool isCompleted() const; //今日单词是否背完
};

#endif