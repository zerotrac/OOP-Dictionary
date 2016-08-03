#ifndef Q_WORDTESTINGRET_H
#define Q_WORDTESTINGRET_H

#include <QWidget>
#include "ui_q_wordtestingret.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "q_wordtestingproc.h"

class Q_WordtestingRet : public QWidget
{
	Q_OBJECT

public:
	Q_WordtestingRet(QWidget *parent = 0);
	~Q_WordtestingRet();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Q_WordtestingProc *q_WordtestingProc;

public slots:
	void slot_yes();
	void slot_no();

private:
	Ui::Q_WordtestingRet ui;
};

#endif // Q_WORDTESTINGRET_H
