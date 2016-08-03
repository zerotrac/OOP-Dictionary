#ifndef Q_WORDSEARCHING_H
#define Q_WORDSEARCHING_H

#include <QWidget>
#include "ui_q_wordsearching.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "Command/Wordsearching.h"
#include "Command/Wordlist.h"
#include "Command/Word.h"

class Q_Wordsearching : public QWidget
{
	Q_OBJECT

public:
	Q_Wordsearching(QWidget *parent = 0);
	~Q_Wordsearching();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Wordsearching *wordsearching;
	Wordlist *wordlist;
	Word *word;

public:
	void search_clear();
	void clear();

public slots:
	void slot_back();
	void slot_prefix();
	void slot_precise();
	void slot_display();
	void slot_history();

	void slot_add1();
	void slot_add2();
	void slot_complete1();
	void slot_complete2();
	void slot_delete1();
	void slot_delete2();

private:
	Ui::Q_Wordsearching ui;
};

#endif // Q_WORDSEARCHING_H
