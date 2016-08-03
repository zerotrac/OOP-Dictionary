//最初的界面

#ifndef Q_INTERFACE_H
#define Q_INTERFACE_H

#include <QWidget>
#include "ui_q_interface.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_checkexit.h"
#include "q_register.h"
#include "q_login.h"
#include "Command/Administration.h"

class Q_Interface : public QWidget
{
	Q_OBJECT

public:
	Q_Interface(QWidget *parent = 0);
	~Q_Interface();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_CheckExit *q_CheckExit;
	Q_Register *q_Register;
	Q_Login *q_Login;
	Administration *administration;

public slots:
	void slot_Finished();
	void slot_Killed();
	void slot_Register();
	void slot_Login();

private:
	Ui::Q_Interface ui;
};

#endif // Q_INTERFACE_H
