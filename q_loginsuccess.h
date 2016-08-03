#ifndef Q_LOGINSUCCESS_H
#define Q_LOGINSUCCESS_H

#include <QWidget>
#include "ui_q_loginsuccess.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_login.h"
#include "q_selection.h"

class Q_LoginSuccess : public QWidget
{
	Q_OBJECT

public:
	Q_LoginSuccess(QWidget *parent = 0);
	~Q_LoginSuccess();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Login *q_Login;
	Q_Selection *q_Selection;

public slots:
	void slot_login();

private:
	Ui::Q_LoginSuccess ui;
};

#endif // Q_LOGINSUCCESS_H
