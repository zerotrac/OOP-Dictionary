#ifndef Q_CHECKEXIT_H
#define Q_CHECKEXIT_H

#include <QWidget>
#include "ui_q_checkexit.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_interface.h"

class Q_CheckExit : public QWidget
{
	Q_OBJECT

public:
	Q_CheckExit(QWidget *parent = 0);
	~Q_CheckExit();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Interface *q_Interface;

public slots:
	void slot_ChooseYes();
	void slot_ChooseNo();

private:
	Ui::Q_CheckExit ui;
};

#endif // Q_CHECKEXIT_H
