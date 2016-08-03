#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#ifdef __linux__
#define _SLASH (std::string)"/"
#elif _WIN32
#define _SLASH (std::string)"\\"
#elif __APPLE__
#define _SLASH (std::string)"/"
#endif

#include "User.h"
#include "Wordlist.h"
#include "Strategy.h"
#include <vector>

class Administration {
private:
	std::vector <User*> users;//用户列表
	User *curUser;
	int userNumber;//用户个数

public:
	Wordlist *wordlist_cet4;
	Wordlist *wordlist_cet6;
	Wordlist *wordlist_toefl;

public:
	Administration();
	~Administration() {}

	//管理修改操作
	bool addUser(User* user, int = -1);//添加一个用户，真值表示添加成功

	//管理查询操作
	int getUserNumber() const { return userNumber; }//查询用户个数
	User *getCurUser() const {return curUser;}
	std::string getCurUserName() const {return curUser->userName;}

	//查询是否登陆成功，0表示登陆成功，1表示用户名不存在，2表示密码不正确
	//如果登录成功就会初始化
	int checkLogin(std::string userName, std::string userKey);
	void logout();
	User *findUserName(std::string userName);//寻找用户名，找到就返回用户指针，否则为空指针
	
	//管理输出操作（调试用）
	friend std::ostream &operator << (std::ostream &, const Administration *);
	void output() const;
};

#endif // !ADMINISTRATION_H
