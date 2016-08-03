#ifndef Q_REGISTERSUCCESS_H
#define Q_REGISTERSUCCESS_H

#include <QWidget>
#include "ui_q_registersuccess.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_register.h"
#include "q_interface.h"

class Q_RegisterSuccess : public QWidget
{
	Q_OBJECT

public:
	Q_RegisterSuccess(QWidget *parent = 0);
	~Q_RegisterSuccess();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Register *q_Register;
	Q_Interface *q_Interface;

public slots:
	void slot_register();

private:
	Ui::Q_RegisterSuccess ui;
};

#endif // Q_REGISTERSUCCESS_H
