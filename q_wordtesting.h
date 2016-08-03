#ifndef Q_WORDTESTING_H
#define Q_WORDTESTING_H

#include <QWidget>
#include "ui_q_wordtesting.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "q_wordtestingproc.h"
#include "Command/Wordlist.h"

class Q_Wordtesting : public QWidget
{
	Q_OBJECT

public:
	Q_Wordtesting(QWidget *parent = 0);
	~Q_Wordtesting();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Q_WordtestingProc *q_WordtestingProc;
	Wordlist *wordlist_cet4;
	Wordlist *wordlist_cet6;
	Wordlist *wordlist_toefl;

public slots:
	void slot_back();
	void slot_start();

private:
	Ui::Q_Wordtesting ui;
};

#endif // Q_WORDTESTING_H
