#include "User.h"
#include <fstream>

#define FLAG_CET_4 0
#define FLAG_CET_6 1
#define FLAG_TOEFL 2

User::User(std::string _userName, std::string _userKey):userName(_userName),userKey(_userKey)
{
	cet_4 = nullptr;
	cet_6 = nullptr;
	toefl = nullptr;
}

std::ostream & operator<<(std::ostream &out, const User &user)
{
	out << user.userName << " " << user.userKey;
	return out;
}

void User::init(int flag, Wordreciting *&wordreciting)
{
	std::string st;
	if (flag == FLAG_CET_4)
	{
		st = "/cet-4_";
	}
	if (flag == FLAG_CET_6)
	{
		st = "/cet-6_";
	}
	if (flag == FLAG_TOEFL)
	{
		st = "/toefl_";
	}

    std::ifstream f1("Users/" + userName + st + "word.txt");
    std::ifstream f2("Users/" + userName + st + "meaning.txt");
	std::ifstream f3("Users/" + userName + st + "level.txt");
	std::ifstream f4("Users/" + userName + st + "strategy.txt");

    int n = 0;
    f1 >> n, f2 >> n, f3 >> n;
	if (n != -1)
	{
		Wordlist *wordlist = new Wordlist();
		for (int i = 0; i < n; i++)
		{
			std::string st;
			int x;

			Word *word = new Word();
			f1 >> st; word->updateName(st);
			f2 >> st; word->updateMeaning(st);
			f3 >> x; word->setLevel(x);
            wordlist->addWord(word);
		}

		wordreciting = new Wordreciting(wordlist);
		f4 >> n; wordreciting->setProportion(n);
		f4 >> n; wordreciting->setDailyNumber(n);
		f4 >> n; wordreciting->setRandom(n);
		f4 >> n; if (n) wordreciting->setStart();
	}
	else
	{
		wordreciting = nullptr;
	}

	f1.close();
	f2.close();
	f3.close();
	f4.close();
}

void User::outit(int flag, Wordreciting *wordreciting)
{
	std::string st;
	if (flag == FLAG_CET_4)
	{
		st = "/cet-4_";
	}
	if (flag == FLAG_CET_6)
	{
		st = "/cet-6_";
	}
	if (flag == FLAG_TOEFL)
	{
		st = "/toefl_";
	}

    std::ofstream f1("Users/" + userName + st + "word.txt");
    std::ofstream f2("Users/" + userName + st + "meaning.txt");
	std::ofstream f3("Users/" + userName + st + "level.txt");
	std::ofstream f4("Users/" + userName + st + "strategy.txt");

	int n = wordreciting->size();
	f1 << n << std::endl;
	f2 << n << std::endl;
	f3 << n << std::endl;
	for (int i = 0; i < n; i++)
	{
		Word *word = wordreciting->getWord(i);
		f1 << word->getName() << std::endl;
		f2 << word->getMeaning(0) << std::endl;
		f3 << word->getLevel() << std::endl;
	}

	f4 << wordreciting->getProportion() << std::endl;
	f4 << wordreciting->getDailyNumber() << std::endl;
	f4 << wordreciting->getRandom() << std::endl;
    f4 << wordreciting->ifStart() << std::endl;

	f1.close();
	f2.close();
	f3.close();
	f4.close();
}

void User::initialize()
{
	init(FLAG_CET_4, cet_4);
	init(FLAG_CET_6, cet_6);
	init(FLAG_TOEFL, toefl);
}

void User::output(Wordreciting *wordreciting)
{
	if (wordreciting == cet_4) outit(0, wordreciting);
	if (wordreciting == cet_6) outit(1, wordreciting);
	if (wordreciting == toefl) outit(2, wordreciting);
}

int User::getWordCount(int flag)
{
	Wordreciting *wordreciting;
	if (flag == FLAG_CET_4) wordreciting = cet_4;
	if (flag == FLAG_CET_6) wordreciting = cet_6;
	if (flag == FLAG_TOEFL) wordreciting = toefl;

	if (wordreciting == nullptr) return 0;
	return wordreciting->size();
}

int User::getPercent(int flag)
{
	Wordreciting *wordreciting;
	if (flag == FLAG_CET_4) wordreciting = cet_4;
	if (flag == FLAG_CET_6) wordreciting = cet_6;
	if (flag == FLAG_TOEFL) wordreciting = toefl;

	if (wordreciting == nullptr) return 0;
	return wordreciting->getPercent();
}

Wordreciting * User::getWordreciting(int flag)
{
	switch (flag)
	{
	case FLAG_CET_4:
		return cet_4;
	case FLAG_CET_6:
		return cet_6;
	case FLAG_TOEFL:
		return toefl;
	}
	return nullptr;
}

void User::setWordreciting(int flag,Wordlist *wl)
{
    switch (flag)
    {
        case FLAG_CET_4:
            cet_4 = new Wordreciting(wl);
            return;
        case FLAG_CET_6:
            cet_6 = new Wordreciting(wl);
            return;
        case FLAG_TOEFL:
            toefl = new Wordreciting(wl);
            return;
        default:
            break;
    }
    return;
}

void User::output() const
{
	std::cout << this;
}
