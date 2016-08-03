#ifndef USER_H
#define USER_H

#include "Wordreciting.h"
#include <string>

class User {
	friend class Administration;

private:
	std::string userName;//用户名
	std::string userKey;//用户密码
	Wordreciting *cet_4;
	Wordreciting *cet_6;
	Wordreciting *toefl;

public:
	User(std::string _userName,std::string _userKey);
	~User() {}

	void init(int, Wordreciting *&); //这个和outit()不用管
	void outit(int, Wordreciting *);

	void initialize(); //用户初始化
	void output(Wordreciting *); //背完单词之后记录到本地

	int getWordCount(int flag); //返回某个Wordreciting的单词总数，没开始返回0
	int getPercent(int flag); //返回某个Wordrecting的进度(0~100，没开始返回0)

	//用户查询操作
	std::string getUserName() { return userName; }
	std::string getUserKey() { return userKey; }
	Wordreciting* getWordreciting(int flag);
    void setWordreciting(int flag,Wordlist *wl);

	//用户输出操作（调试用）
	friend std::ostream &operator << (std::ostream &, const User &);
	void output() const;
};

#endif // !USER_H
