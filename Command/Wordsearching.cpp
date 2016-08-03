#include "Wordsearching.h"
#include <fstream>

int Wordsearching::maxHistory = 100;
std::string Wordsearching::historyCatalogue = "Vocabulary/dictionary/dictionary_history.txt";
std::string Wordsearching::sentenceCatalogue = "Vocabulary/dictionary/dictionary_sentence.txt";

bool operator < (const p_IW &x, const p_IW &y)
{
	return x.first < y.first;
};

Wordsearching::Wordsearching(Wordlist *r_wordlist)
{
	root = new Trie();
	root->addWord(r_wordlist);
	wordlist = r_wordlist;
	curHistorySize = 0;
}

Wordsearching::~Wordsearching()
{
	//和Trie一样这里应该也不用写什么
}

void Wordsearching::addWord(const Wordlist *wordlist)
{
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		addWord(word);
	}
}

void Wordsearching::addWord(Word *word)
{
	root->addWord(word);
	addHistory(word);
}

Word *Wordsearching::findPreciseWord(std::string st)
{
	Word *word = root->findPreciseWord(st);
	if (word != nullptr) addHistory(word);
	return word;
}

Word *Wordsearching::findPreciseWord(int x)
{
	Word *word = root->findPreciseWord(x);
	return word;
}

Wordlist *Wordsearching::findPrefixWord(std::string st)
{
	return root->findPrefixWord(st);
}

int Wordsearching::getTotalWordCount() const
{
	return root->getWordCount();
}

void Wordsearching::addHistory(Word *word)
{
	for (auto iter = history.begin(); iter != history.end(); iter++)
	{
		if (iter->second == word)
		{
			history.erase(iter);
			curHistorySize--;
			break;
		}
	}
	if (history.size() == maxHistory)
	{
		for (auto iter = history.begin(); iter != history.end(); iter++)
		{
			if (iter->first == maxHistory)
			{
				history.erase(iter);
				curHistorySize--;
				break;
			}
		}
	}

	curHistorySize++;
	std::set <p_IW> replace;
	replace.insert(std::make_pair(0, word));
	int relab = 1;
	for (auto iter = history.begin(); iter != history.end(); iter++, relab++)
	{
		replace.insert(std::make_pair(relab, iter->second));
	}
	history = replace;
	replace.clear();

	setdownHistory();
}

Wordlist *Wordsearching::getHistory()
{
	Wordlist *wordlist = new Wordlist();
	for (auto iter = history.begin(); iter != history.end(); iter++)
	{
		wordlist->addWord(iter->second);
	}
	return wordlist;
}

void Wordsearching::clearHistory()
{
	curHistorySize = 0;
	history.clear();
}

void Wordsearching::setupHistory()
{
	std::ifstream in(historyCatalogue);
	std::string wd;
	int n;

	clearHistory();
	Wordlist *ls_wordlist = new Wordlist();
	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> wd;
		Word *word = root->findPreciseWord(wd);
		ls_wordlist->addWord(word);
	}
	clearHistory();
	for (int i = ls_wordlist->size() - 1; i >= 0; i--)
	{
		addHistory(ls_wordlist->getWord(i));
	}

	in.close();
}

void Wordsearching::setdownHistory()
{
	std::ofstream out(historyCatalogue);
	
	out << history.size() << std::endl;
	for (auto iter = history.begin(); iter != history.end(); iter++)
	{
		out << iter->second->getName() << std::endl;
	}
	
	out.close();
}

void Wordsearching::setdownSentence()
{
	std::ofstream out(sentenceCatalogue);

	int n = wordlist->size();
	out << n << std::endl;
	for (int i = 0; i < n; i++)
	{
		Word *word = wordlist->getWord(i);
		int x = word->getSentenceSize();
		out << x << std::endl;
		for (int j = 0; j < x; j++)
		{
			std::string st = word->getSentence(j);
			out << st << std::endl;
		}
	}

	out.close();
}

std::ostream &operator << (std::ostream &out, const Wordsearching &wordsearching)
{
	out << "历史记录：";
	for (auto iter = wordsearching.history.begin(); iter != wordsearching.history.end(); iter++)
	{
		out << std::endl << (iter->second)->getName();
	}
	return out;
}

void Wordsearching::output() const
{
	std::cout << this;
}