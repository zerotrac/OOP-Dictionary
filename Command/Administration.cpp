#include "Administration.h"
#include <cstring>
#include <fstream>

using namespace std;

Administration::Administration()
{
    std::ifstream userDataFile("Users/user.txt");

    int tempNumber;
	userDataFile >> tempNumber;
    userNumber = 0;
    for (int i = 0; i < tempNumber; ++i)
	{
        std::string userName, userKey;
        userDataFile >> userName;
        userDataFile >> userKey;
        User *user_ptr = new User(userName, userKey);
        addUser(user_ptr, 1);
    }
    userDataFile.close();

	curUser = nullptr;
}


User* Administration::findUserName(string userName)//应该还有比暴搜更效率的办法吧。。。
{
	for (auto i = users.begin(); i != users.end(); ++i)
	{
		if (userName == (*i)->getUserName())
			return *i;
	}
	return nullptr;
}

bool Administration::addUser(User * user, int check)
{
    if (findUserName(user->getUserName()) != nullptr)
	{
		return false;//用户名重复，不能创建
	}
	else
	{
		users.push_back(user);
		++userNumber;

        std::ofstream userDataFile("Users/user.txt");

		userDataFile << userNumber << endl;
		for (auto i = users.begin(); i != users.end(); ++i)
		{
			userDataFile << (*i)->userName << endl;
			userDataFile << (*i)->userKey << endl;
		}

		if (check == -1)
		{
			std::string st = "Users" + _SLASH + user->getUserName();
			std::string st1 = "mkdir " + st;
			std::system(st1.c_str());

			std::ofstream f1(st + "/cet-4_word.txt");
			std::ofstream f2(st + "/cet-4_meaning.txt");
			std::ofstream f3(st + "/cet-4_level.txt");
			int n1 = wordlist_cet4->size();
			f1 << n1 << std::endl;
			f2 << n1 << std::endl;
			f3 << n1 << std::endl;
			for (int i = 0; i < n1; i++)
			{
				f1 << wordlist_cet4->getWord(i)->getName() << std::endl;
				f2 << wordlist_cet4->getWord(i)->getMeaning(0) << std::endl;
				f3 << Word::getDefaultLevel() << std::endl;
			}

			std::ofstream f4(st + "/cet-6_word.txt");
			std::ofstream f5(st + "/cet-6_meaning.txt");
			std::ofstream f6(st + "/cet-6_level.txt");
			int n2 = wordlist_cet6->size();
			f4 << n2 << std::endl;
			f5 << n2 << std::endl;
			f6 << n2 << std::endl;
			for (int i = 0; i < n2; i++)
			{
				f4 << wordlist_cet6->getWord(i)->getName() << std::endl;
				f5 << wordlist_cet6->getWord(i)->getMeaning(0) << std::endl;
				f6 << Word::getDefaultLevel() << std::endl;
			}

			std::ofstream f7(st + "/toefl_word.txt");
			std::ofstream f8(st + "/toefl_meaning.txt");
			std::ofstream f9(st + "/toefl_level.txt");
			int n3 = wordlist_toefl->size();
			f7 << n3 << std::endl;
			f8 << n3 << std::endl;
			f9 << n3 << std::endl;
			for (int i = 0; i < n3; i++)
			{
				f7 << wordlist_toefl->getWord(i)->getName() << std::endl;
				f8 << wordlist_toefl->getWord(i)->getMeaning(0) << std::endl;
				f9 << Word::getDefaultLevel() << std::endl;
			}

			std::ofstream s1(st + "/cet-4_strategy.txt");
			std::ofstream s2(st + "/cet-6_strategy.txt");
			std::ofstream s3(st + "/toefl_strategy.txt");

            s1 << Strategy::getDefaultProportion() << std::endl;
            s1 << Strategy::getDefaultDailyNumber() << std::endl;
			s1 << 0 << std::endl; //这个0表示selectRandom = false
			s1 << 0 << std::endl; //这个0表示isStart = false

            s2 << Strategy::getDefaultProportion() << std::endl;
            s2 << Strategy::getDefaultDailyNumber() << std::endl;
			s2 << 0 << std::endl; //这个0表示selectRandom = false
			s2 << 0 << std::endl; //这个0表示isStart = false

            s3 << Strategy::getDefaultProportion() << std::endl;
            s3 << Strategy::getDefaultDailyNumber() << std::endl;
			s3 << 0 << std::endl; //这个0表示selectRandom = false
			s3 << 0 << std::endl; //这个0表示isStart = false

			f1.close(); f2.close(); f3.close();
			f4.close(); f5.close(); f6.close();
			f7.close(); f8.close(); f9.close();
			s1.close(); s2.close(); s3.close();
		}
		return true;//创建成功
	}
}

int Administration::checkLogin(string userName, string userKey)
{
	User *user_ptr = findUserName(userName);
	if (user_ptr == nullptr)
	{
		return 1;
	}
	else
	{
		if (user_ptr->userKey != userKey)
		{
			return 2;
		}
		else
		{
			curUser = user_ptr;
			curUser->initialize();
			return 0;
		}
	}
}

void Administration::logout()
{
	curUser = nullptr;
}

ostream & operator<<(ostream &out, const Administration *administration)
{
	out <<"User Number: "<< administration->getUserNumber();
	for (auto i = administration->users.begin(); i != administration->users.end(); ++i)
	{
		out << endl << *i;
	}
	return out;
}

void Administration::output() const
{
	cout << this;
}
