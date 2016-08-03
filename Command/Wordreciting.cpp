#include "Wordreciting.h"
#include <queue>

Wordreciting::Wordreciting(Wordlist *rhs)
{
	ordered = wordlist = rhs;
	random = new Wordlist(rhs);
	random->shuffle();
	strategy = new Strategy;
	isStart = false;
}

Wordreciting::~Wordreciting()
{

}

void Wordreciting::start()
{
	isStart = true;
    wordlist = (strategy->selectRandom ? random : ordered);
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		word->setLevel();
	}
}

void Wordreciting::clear()
{
	isStart = false;
	random->clear();
	delete random;
}

void Wordreciting::startDailyMission()
{
	int mLevel = Word::getMaxLevel();
	std::vector <std::queue <Word*>> wordWithLevel(mLevel + 1);
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		int wLevel = word->getLevel();
		if (wLevel != -1)
		{
			wordWithLevel[wLevel].push(word);
		}
	}

	std::vector <int> probability;
	for (int i = 0; i < strategy->newProportion; i++)
	{
		probability.push_back(Word::getDefaultLevel());
	}
	for (int i = 0; i <= mLevel; i++)
	{
		if (i != Word::getDefaultLevel())
		{
			int tot = (mLevel + 2) * (mLevel + 1) / 2;
			int jm = static_cast <int> ((100 - strategy->newProportion) * ((1.0 + i) / tot));
			if (jm < 1) jm = 1;
			for (int j = 0; j < jm; j++) probability.push_back(i);
		}
	}
	while (probability.size() != 100)
	{
		probability.push_back(Word::getDefaultLevel());
	}
	std::random_shuffle(probability.begin(), probability.end());

    dailywordreciting = new DailyWordreciting();
	for (int i = 0; i < strategy->dailyNumber; i++)
	{
		bool finished = true;
		for (int j = 0; j <= mLevel; j++)
		{
			if (!wordWithLevel[j].empty())
			{
				finished = false;
				break;
			}
		}
		if (finished) break;

		while (1)
		{
            int rd = probability[rand() % probability.size()];
			if (!wordWithLevel[rd].empty())
			{
				dailywordreciting->push(wordWithLevel[rd].front(), 1);
				wordWithLevel[rd].pop();
				break;
			}
		}
	}

    curWord = nullptr;
	toNext();
}

void Wordreciting::toNext()
{
	if (curWord != nullptr)
	{
        dailywordreciting->pop(curWordGroup);
        dailywordreciting->push(curWord, regWordGroup);
	}

	if (isDailyCompleted()) return;

	std::vector <int> probability;
	for (int i = 0; i < 2; i++)
	{
        for (int j = 0; j < dailywordreciting->size[i]; j++)
		{
			probability.push_back(i);
		}
	}
	std::random_shuffle(probability.begin(), probability.end());

	while (1)
	{
        int rd = probability[rand() % probability.size()];
		if (!dailywordreciting->words[rd].empty())
		{
			curWord = dailywordreciting->words[rd].front();
			curWordGroup = rd;
			regWordGroup = rd;
            break;
		}
	}
}

void Wordreciting::giveAnswer(int x)
{
	if (x == 0)
	{
		curWord->incLevel();
		if (regWordGroup) regWordGroup--;
	}
	else
	{
		curWord->decLevel();
		regWordGroup++;
	}
}

void Wordreciting::kill()
{
	curWord->setComplete();
	regWordGroup = 2;
}

void Wordreciting::regret()
{
	regWordGroup = curWordGroup;
    if (regWordGroup) regWordGroup--;
    curWord->incLevel();
    curWord->incLevel();
}


int Wordreciting::getDailyCount(int x)
{
    return dailywordreciting->size[x];
}

bool Wordreciting::isCompleted() const
{
	bool b = true;
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		if (word->getLevel() != Word::getMinLevel())
		{
			b = false;
			break;
		}
	}
	return b;
}

bool Wordreciting::isDailyCompleted() const
{
	return dailywordreciting->isCompleted();
}

int Wordreciting::size() const
{
	return wordlist->size();
}

Word *Wordreciting::getWord(int x) const
{
	return wordlist->getWord(x);
}

void Wordreciting::setStart()
{
	isStart = true;
}

int Wordreciting::getPercent() const
{
	int x = 0, y = 0;
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		int u = word->getLevel();
		if (u > Word::getDefaultLevel()) u = Word::getDefaultLevel();
		u = Word::getDefaultLevel() - u;
		
		x += u;
		y += Word::getDefaultLevel() - Word::getMinLevel();
	}
	return static_cast <int> (100.0 * x / y);
}

void Wordreciting::setProportion(int x)
{
	strategy->setProportion(x);
}

void Wordreciting::setDailyNumber(int x)
{
	strategy->setDailyNumber(x);
}

void Wordreciting::setRandom(bool b)
{
	if (!isStart) strategy->setRandom(b);
}
