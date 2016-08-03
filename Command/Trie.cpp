#include "Trie.h"

int Trie::maxMatch = 100;

Trie::Trie()
{
	for (int i = 0; i < 26; i++)
	{
		successor[i] = nullptr;
	}
	iCount = 0;
	word = nullptr;
}

Trie::~Trie()
{
	//字典树的生命周期最长
	//所以析构的时候好像不用做什么
}

//Trie *successor[26]; //子节点指针
//int iCount; //以根节点到当前节点为前缀的单词数量
//Word *word; //如果当前节点是尾节点（某个单词的结尾），那么Word*中存储这个单词的指针，否则为nullptr

void Trie::addWord(const Wordlist *wordlist)
{
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		addWord(word);
	}
}

void Trie::addWord(Word *word)
{
	Trie *cur = this;
	std::string st = word->getName();
	for (size_t i = 0; i < st.size(); i++)
	{
		if (st[i] < 'a' || st[i] > 'z') return;
	}

	for (size_t i = 0; i < st.size(); i++)
	{
		char ch = tolower(st[i]);
		if (cur->successor[ch - 97] == nullptr)
		{
			cur->successor[ch - 97] = new Trie();
		}
		cur = cur->successor[ch - 97];
		cur->iCount++;
	}
	cur->word = word;
	iCount++;
}

Word *Trie::findPreciseWord(std::string st)
{
	Trie *cur = this;
	for (size_t i = 0; i < st.size(); i++)
	{
		char ch = tolower(st[i]);
		if (ch < 'a' || ch > 'z' || cur->successor[ch - 97] == nullptr) return nullptr;
		cur = cur->successor[ch - 97];
	}
	return cur->word;
}

Word *Trie::findPreciseWord(int label)
{
	label++;

	Trie *cur = this;
	while (true)
	{
		bool check = false;
		for (int i = 0; i < 26; i++)
		{
			if (cur->successor[i] != nullptr)
			{
				check = true;
				int wCount = cur->successor[i]->getWordCount();
				if (label > wCount)
				{
					label -= wCount;
				}
				else
				{
					cur = cur->successor[i];
					break;
				}
			}
		}
		if (!check) break;
	}
	return cur->word;
}

Wordlist *Trie::findPrefixWord(std::string st)
{
	Wordlist *wordlist = new Wordlist();
	Trie *cur = this;
	for (size_t i = 0; i < st.size(); i++)
	{
		char ch = tolower(st[i]);
		if (ch < 'a' || ch > 'z' || cur->successor[ch - 97] == nullptr) return wordlist;
		cur = cur->successor[ch - 97];
	}
	deepFirstSearch(cur, wordlist);
	return wordlist;
}

int Trie::getWordCount() const
{
	return iCount;
}

bool Trie::isFinished() const
{
	return word != nullptr;
}

void deepFirstSearch(Trie *trie, Wordlist *wordlist)
{
	if (wordlist->size() == trie->maxMatch) return;
	if (trie->isFinished())
	{
		wordlist->addWord(trie->word);
	}
	for (int i = 0; i < 26; i++)
	{
		if (trie->successor[i] != nullptr) deepFirstSearch(trie->successor[i], wordlist);
	}
}
