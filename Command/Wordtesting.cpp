#include "Wordtesting.h"
#include <algorithm>

int Wordtesting::maxQuery = 50;
int Wordtesting::maxSelection = 4;

Wordtesting::Wordtesting(Wordlist *r_wordlist)
{
	total_wordlist = r_wordlist;
	wordlist = new Wordlist();
}

Wordtesting::~Wordtesting()
{

}

void Wordtesting::getRandomInteger(std::vector <int> &v, int requiredSize, int rangeL, int rangeR)
{
	int curSize = v.size();
	for (int i = curSize + 1; i <= requiredSize; i++)
	{
		while (1)
		{
			bool flag = true;
			int p = rand() % (rangeR - rangeL + 1) + rangeL;
			for (int j = 0; j < i - 1; j++)
			{
				if (v[j] == p)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				v.push_back(p);
				break;
			}
		}
	}
}

void Wordtesting::generateQuery()
{
	std::vector <int> v0;
	getRandomInteger(v0, maxQuery, 0, getTotalWordCount() - 1);

	wordlist->clear();
	for (int i = 0; i < maxQuery; i++)
	{
		wordlist->addWord(total_wordlist->getWord(v0[i]));
	}

	score = 0;
	label = -1;
	toNext();
}

void Wordtesting::restartQuery()
{
	score = 0;
	label = -1;
	toNext();
}

std::string Wordtesting::getQuery(int x) const
{
	Word *word = wordlist->getWord(choose[x]);
	return word->getMeaning(0);
}

Word *Wordtesting::getCurWord() const
{
	Word *word = wordlist->getWord(label);
	return word;
}

int Wordtesting::getLabel() const
{
	return label;
}

int Wordtesting::getQueryCount() const
{
	return maxQuery;
}

int Wordtesting::getScore() const
{
	return score;
}

int Wordtesting::getAnswer() const
{
	return answer;
}

void Wordtesting::outputQuery() const
{
	Word *curWord = wordlist->getWord(label);
	std::string sName = curWord->getName();
	std::cout << sName << std::endl;

	for (int i = 0; i < maxSelection; i++)
	{
		std::cout << static_cast <char> (65 + i) << ". ";
		curWord = wordlist->getWord(choose[i]);
		sName = curWord->getMeaning(0);
		std::cout << sName << std::endl;
	}
}

void Wordtesting::giveAnswer(int gAnswer)
{
	if (answer == gAnswer)
	{
		score += 100 / maxQuery;
	}
}

void Wordtesting::toNext()
{
	label++;
	if (label >= maxQuery) return;

	choose.clear();
	choose.push_back(label);
	getRandomInteger(choose, maxSelection, 0, maxQuery - 1);
	std::random_shuffle(choose.begin(), choose.end());

	for (int i = 0; i < maxSelection; i++)
	{
		if (choose[i] == label) answer = i;
	}
};

void Wordtesting::outputScore() const
{
	std::cout << score << "/" << label + 1 << std::endl;
}

void Wordtesting::outputFinalScore() const
{
	std::cout << score << "/" << maxQuery << std::endl;
};

bool Wordtesting::isFinished() const
{
	return (label >= maxQuery);
}

int Wordtesting::getTotalWordCount() const
{
	return total_wordlist->size();
}
