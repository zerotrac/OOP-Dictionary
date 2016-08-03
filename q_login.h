#ifndef Q_LOGIN_H
#define Q_LOGIN_H

#include <QWidget>
#include "ui_q_login.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_interface.h"
#include "q_loginsuccess.h"
#include "Command/Administration.h"

class Q_Login : public QWidget
{
	Q_OBJECT

public:
	Q_Login(QWidget *parent = 0);
	~Q_Login();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Interface *q_Interface;
	Q_LoginSuccess *q_LoginSuccess;
	Administration *administration;

public:
	void clear();

public slots:
	void slot_Interface();
	void slot_check1();
	void slot_check2();
	void slot_Preparation();

private:
	Ui::Q_Login ui;
};

#endif // Q_LOGIN_H
