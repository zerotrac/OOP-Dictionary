//存储单词的基类
//请使用指针以访问单词的实时信息

#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

typedef std::pair<int, std::string> p_IS; //存储例句的结构，int表示例句的编号，std::string表示例句
bool operator < (const p_IS &, const p_IS &); //例句存储在set中的运算符重载，按例句编号从小到大排序

class Word
{
private:
	std::string name; //单词
	std::vector <std::string> meaning; //单词的解释
	std::set <p_IS> sentence; //单词的例句
	int curMeaningSize; //当前解释的数量
	int curSentenceSize; //当前例句的数量
	
	int level; //单词的等级
	//int difficulty; //单词的难度（想了想level和difficulty只要用一个就行了）

private:
	static int minLevel; //单词等级的下限
	static int maxLevel; //单词等级的上限
	static int defaultLevel; //单词等级的默认值
	static int maxSentenceSize; //例句数量的上限

public:
	Word()
	{
		clear();
	}
	~Word()
	{
		clearMeaning();
		clearSentence();
	}

	//单词私有成员的修改操作，单词和解释分开修改
	void clear(); //单词初始化，清空所有成员
	void updateName(std::string); //修改单词
	void updateMeaning(std::string); //增加单词的一个解释
	void clearMeaning(); //清空单词的所有解释
	void updateSentence(std::string); //增加一个例句
	void deleteSentence(int); //删除int编号的例句
	void clearSentence(); //清空单词的所有例句

	void setParameter(bool); //调整单词的参数，bool表示单词是否背出来
	void setLevel(int = defaultLevel); //将单词的等级变为int，缺省参数为defaultLevel
	void incLevel(int = 1); //将单词的等级增加int
	void decLevel(int = 1); //将单词的等级减少int
	void setComplete(); //将单词设为已背完状态，即再也不会背到这个单词

	//单词私有成员的访问操作
	std::string getName() const; //获取单词
	int getMeaningSize() const; //获取单词解释的数量
	std::string getMeaning(int) const; //获取单词int编号的解释
	int getSentenceSize() const; //获取单词例句的数量
	std::string getSentence(int) const; //获取单词int编号的句子
	int getLevel() const; //获取单词的等级

	//单词私有成员的输出操作（调试用，喜欢用哪种用哪种）
	friend std::ostream &operator << (std::ostream &, const Word &);
	void output() const;

	static int getMinLevel(); //获取单词等级的下限
	static int getMaxLevel(); //获取单词等级的上限
	static int getDefaultLevel(); //获取单词默认等级
};

#endif