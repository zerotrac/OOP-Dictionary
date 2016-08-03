#ifndef Q_REGISTER_H
#define Q_REGISTER_H

#include <QWidget>
#include "ui_q_register.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_interface.h"
#include "q_registersuccess.h"
#include "Command/Administration.h"

class Q_Register : public QWidget
{
	Q_OBJECT

public:
	Q_Register(QWidget *parent = 0);
	~Q_Register();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Interface *q_Interface;
	Q_RegisterSuccess *q_RegisterSuccess;
	Administration *administration;

public:
	void clear();

public slots:
	void slot_Interface();
	void slot_check1();
	void slot_check2();
	void slot_check3();
	void slot_Preparation();

private:
	Ui::Q_Register ui;
};

#endif // Q_REGISTER_H
