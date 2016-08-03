//文本查询基类

#ifndef TEXTSEARCHING_H
#define TEXTSEARCHING_H

#include "Trie.h"
#include "Wordlist.h"

class Textsearching
{

private:

public:
	Textsearching();
	~Textsearching();

    //给定一个句子std::string和词库Wordlist*，返回一个包含std::string和Wordlist*中都出现的词的集合Wordlist*
    Wordlist *search(std::string, Wordlist *wordlist);
};

#endif
