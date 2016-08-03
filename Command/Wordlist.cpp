#include "Wordlist.h"
#include <algorithm>
#include <fstream>

Wordlist::Wordlist()
{
	curSize = 0;
}

Wordlist::Wordlist(std::string st_name, std::string st_meaning, std::string st_sentence)
{
	curSize = 0;
	std::ifstream in_name(st_name);
	std::ifstream in_meaning(st_meaning);
	std::ifstream in_sentence(st_sentence);

	int n;
	in_name >> n, in_meaning >> n, in_sentence >> n;
	for (int i = 0; i < n; i++)
	{
		Word *word = new Word();
		std::string st;
		
		in_name >> st, word->updateName(st);
		in_meaning >> st, word->updateMeaning(st);
		
		int x;
		in_sentence >> x;
		getline(in_sentence, st);
		for (int j = 0; j < x; j++)
		{
			getline(in_sentence, st);
			word->updateSentence(st);
		}
		addWord(word);
	}

	in_name.close();
	in_meaning.close();
	in_sentence.close();
}

Wordlist::Wordlist(Wordlist *rhs)
{
	curSize = rhs->curSize;
	words = rhs->words;
}

Wordlist::~Wordlist()
{
	clear();
}

void Wordlist::clear()
{
	curSize = 0;
	words.clear();
}

void Wordlist::addWord(Word *word)
{
	curSize++;
	words.push_back(word);
}

void Wordlist::shuffle()
{
	std::random_shuffle(words.begin(), words.end());
}

int Wordlist::size() const
{
	return curSize;
}

Word *Wordlist::getWord(int label) const
{
	if (label >= curSize) return nullptr;
	return words[label];
}

std::ostream &operator << (std::ostream &out, const Wordlist &wordlist)
{
	for (int i = 0; i < wordlist.size(); i++)
	{
		out << *wordlist.words[i] << std::endl;
	}
	return out;
}

void Wordlist::output() const
{
	std::cout << this;
}