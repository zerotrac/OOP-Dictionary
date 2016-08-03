#ifndef Q_WORDRECITING_H
#define Q_WORDRECITING_H

#include <QWidget>
#include "ui_q_wordreciting.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "q_wordrecitinginit.h"
#include "q_wordrecitingpara.h"
#include "Command/user.h"
#include "Command/wordreciting.h"
#include "Command/Tostring.h"

class Q_Wordreciting : public QWidget
{
	Q_OBJECT

public:
	Q_Wordreciting(QWidget *parent = 0);
	~Q_Wordreciting();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Q_WordrecitingInit *q_WordrecitingInit;
	Q_WordrecitingPara *q_WordrecitingPara;
	User *user;
	Wordreciting *wordreciting;

public:
	void start(User *);
	void init();
	void para();

public slots:
    void slot_back();
	void slot_choose0();
	void slot_choose1();
	void slot_choose2();

private:
	Ui::Q_Wordreciting ui;
};

#endif // Q_WORDRECITING_H
