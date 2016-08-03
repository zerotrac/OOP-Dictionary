//单词查找功能基类
//Wordsearching类的成员函数和Trie的几乎一样，只是实现了一个封装

#ifndef WORDSEARCHING_H
#define WORDSEARCHING_H

#include "Trie.h"

typedef std::pair<int, Word*> p_IW; //存储历史记录的结构，int表示单词的编号，Word*表示单词
bool operator < (const p_IW &, const p_IW &); //历史记录存储在set中的运算符重载，按例句编号从小到大排序

class Wordsearching
{

private:
	Trie *root; //字典树的根节点
	Wordlist *wordlist; //字典树中的所有单词，方便查询
	std::set <p_IW> history; //历史记录
	int curHistorySize; //当前历史记录的条数

private:
	static int maxHistory; //最多存储的历史记录数量
	static std::string historyCatalogue; //历史记录存放的目录
	static std::string sentenceCatalogue; //例句存放的目录

public:
	Wordsearching(Wordlist *); //默认构造函数中必须包含一个词条
	~Wordsearching();

	//封装Trie的成员函数
	void addWord(const Wordlist *);
	void addWord(Word *);

	Word *findPreciseWord(std::string);
	Word *findPreciseWord(int);
	Wordlist *findPrefixWord(std::string);

	//Wordsearching的成员函数
	int getTotalWordCount() const; //返回词典中总的单词数量
	void addHistory(Word *); //增加一条历史记录
	Wordlist *getHistory(); //返回历史记录
	void clearHistory(); //清空历史记录
	
	void setupHistory(); //从文件中读取历史记录
	void setdownHistory(); //将历史记录输出到文件
	void setdownSentence(); //将例句输出到文件

	//历史记录输出操作（调试用）
	friend std::ostream &operator << (std::ostream &, const Wordsearching &);
	void output() const;
};

#endif
