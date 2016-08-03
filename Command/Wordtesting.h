//单词测试基类

#ifndef WORDTESTING_H
#define WORDTESTING_H

#include "Wordlist.h"
#include "Trie.h"

class Wordtesting
{

private:
	Wordlist *total_wordlist; //所有单词
	Wordlist *wordlist; //用于测试的单词存在Wordlist里面，同时给出的选项也从这些单词的解释中随机抽取
	int score; //单词测试的当前分数
	int label; //单词测试的当前题号
	int answer; //当前题号的标准答案
	std::vector <int> choose; //当前题号对应的选项编号

private:
	static int maxQuery; //题目数量
	static int maxSelection; //选项数量
public:
	Wordtesting(Wordlist *); //默认构造函数中必须包含一个单词列表
	~Wordtesting();

	//一些关于随机数的成员函数（为生成题目服务，在类外面用不到）
	void getRandomInteger(std::vector <int> &, int, int, int);

	//单词测试初始化
	void generateQuery(); //生成一套新的题目
	void restartQuery(); //重新开始测试这套题目

	std::string getQuery(int) const; //返回第int个选项
	Word *getCurWord() const; //返回当前题中的单词
	int getLabel() const; //返回当前题号
	int getQueryCount() const; //返回总题数
	int getScore() const; //返回当前分数
	int getAnswer() const; //返回当前题的答案

	void outputQuery() const; //输出当前题的题面
	void giveAnswer(int); //用户给出当前题的答案并评分（不会自动跳转到下一题）
	void toNext(); //跳转到下一题
	/*
	当生成新的题目时，默认的当前题号是0，所以需要这样写
	while (!isFinished())
	{
		Do something ...
		toNext();
	}
	*/
	void outputScore() const; //输出当前分数，格式为（分数/题数）
	void outputFinalScore() const; //输出最后的分数
	bool isFinished() const; //这套题是否测试完毕
	
	int getTotalWordCount() const; //返回词典中总的单词数量
};

#endif