// 单词列表基类
// 其实就是对std::vector的封装

#ifndef WORDLIST_H
#define WORDLIST_H

#include "Word.h"
#include <vector>

class Wordlist
{
private:
	int curSize; //单词列表的当前长度
	std::vector <Word*> words; //单词列表数组

public:
	Wordlist();
	Wordlist(std::string, std::string, std::string); //文件读入
	Wordlist(Wordlist *);
	~Wordlist();

	//单词列表修改操作
	void clear(); //清空单词列表
	void addWord(Word *); //添加一个单词
	void shuffle(); //改变整个单词列表的顺序

	//单词列表查询操作
	int size() const; //查询单词列表的当前长度
	Word* getWord(int) const; //查询位置为int的单词

	//单词列表输出操作（调试用）
	friend std::ostream &operator << (std::ostream &, const Wordlist &);
	void output() const;
};

#endif