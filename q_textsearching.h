#ifndef Q_TEXTSEARCHING_H
#define Q_TEXTSEARCHING_H

#include <QWidget>
#include "ui_q_textsearching.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "Command/Textsearching.h"
#include "Command/Wordlist.h"

class Q_Textsearching : public QWidget
{
	Q_OBJECT

public:
	Q_Textsearching(QWidget *parent = 0);
	~Q_Textsearching();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Textsearching *textsearching;
	Wordlist *wordlist_cet4;
	Wordlist *wordlist_cet6;
	Wordlist *wordlist_toefl;

public:
	void init();

public slots:
	void slot_back();
	void slot_search();

private:
	Ui::Q_Textsearching ui;
};

#endif // Q_TEXTSEARCHING_H
