#ifndef Q_SELECTION_H
#define Q_SELECTION_H

#include <QWidget>
#include "ui_q_selection.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_interface.h"
#include "q_logoutsuccess.h"
#include "q_wordsearching.h"
#include "q_wordtesting.h"
#include "q_wordreciting.h"
#include "q_textsearching.h"
#include "Command/Administration.h"

class Q_Selection : public QWidget
{
	Q_OBJECT

public:
	Q_Selection(QWidget *parent = 0);
	~Q_Selection();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Interface *q_Interface;
	Q_LogoutSuccess *q_LogoutSuccess;
	Q_Wordsearching *q_Wordsearching;
	Q_Wordtesting *q_Wordtesting;
	Q_Wordreciting *q_Wordreciting;
	Q_Textsearching *q_Textsearching;
	Administration *administration;

public:
	void start();

public slots:
	void slot_logout();
	void slot_wordsearching();
	void slot_wordtesting();
	void slot_wordreciting();
	void slot_textsearching();

private:
	Ui::Q_Selection ui;
};

#endif // Q_SELECTION_H
