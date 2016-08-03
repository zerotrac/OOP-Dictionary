#ifndef Q_WORDTESTINGFIN_H
#define Q_WORDTESTINGFIN_H

#include <QWidget>
#include "ui_q_wordtestingfin.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "q_wordtestingproc.h"
#include "Command/Administration.h"

class Q_WordtestingFin : public QWidget
{
	Q_OBJECT

public:
	Q_WordtestingFin(QWidget *parent = 0);
	~Q_WordtestingFin();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Q_WordtestingProc *q_WordtestingProc;
	Administration *administration;

public:
	void start(int);

public slots:
	void slot_back();

private:
	Ui::Q_WordtestingFin ui;
};

#endif // Q_WORDTESTINGFIN_H
