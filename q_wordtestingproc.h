#ifndef Q_WORDTESTINGPROC_H
#define Q_WORDTESTINGPROC_H

#include <QWidget>
#include "ui_q_wordtestingproc.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_wordtesting.h"
#include "q_wordtestingret.h"
#include "q_wordtestingfin.h"
#include "Command/Wordtesting.h"

class Q_WordtestingProc : public QWidget
{
	Q_OBJECT

public:
	Q_WordtestingProc(QWidget *parent = 0);
	~Q_WordtestingProc();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Wordtesting *q_Wordtesting;
	Q_WordtestingRet *q_WordtestingRet;
	Q_WordtestingFin *q_WordtestingFin;
	Wordtesting *wordtesting;

public:
	void display();
	void del();

public slots:
	void slot_submit();
	void slot_tonext();
	void slot_abandon();

private:
	Ui::Q_WordtestingProc ui;
};

#endif // Q_WORDTESTINGPROC_H
