//字典树基类

#ifndef TRIE_H
#define TRIE_H

#include "Word.h"
#include "Wordlist.h"

class Trie
{

private:
	Trie *successor[26]; //子节点指针
	int iCount; //以根节点到当前节点为前缀的单词数量
	Word *word; //如果当前节点是尾节点（某个单词的结尾），那么Word*中存储这个单词的指针，否则为nullptr

private:
	static int maxMatch; //前缀查询时返回的最多单词数量

public:
	Trie();
	~Trie();

	//字典树添加单词操作
	//注意：单词不能重复添加！即可能有些单词在四级中又在六级中出现！
	void addWord(const Wordlist *);
	void addWord(Word *);

	//字典树查询操作
	Word *findPreciseWord(std::string); //精确查询，没有返回空指针
	Word *findPreciseWord(int); //精确查询某个编号的单词
	Wordlist *findPrefixWord(std::string); //前缀查询
	int getWordCount() const; //查询iCount
	bool isFinished() const; //查询是否为尾节点

	friend void deepFirstSearch(Trie *, Wordlist *);
};

#endif