#ifndef Q_WORDRECITINGPARA_H
#define Q_WORDRECITINGPARA_H

#include <QWidget>
#include "ui_q_wordrecitingpara.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_wordreciting.h"
#include "q_wordrecitingproc.h"
#include "Command/Wordreciting.h"
#include "Command/User.h"
#include "Command/Tostring.h"

class Q_WordrecitingPara : public QWidget
{
	Q_OBJECT

public:
	Q_WordrecitingPara(QWidget *parent = 0);
	~Q_WordrecitingPara();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Wordreciting *q_Wordreciting;
    Q_WordrecitingProc *q_WordrecitingProc;
	Wordreciting *wordreciting;
	User *user;

public:
	void start(Wordreciting *, User *);
    void changeValue();

public slots:
	void slot_start();
	void slot_back();
    void slot_number();
    void slot_proportion();

private:
	Ui::Q_WordrecitingPara ui;
};

#endif // Q_WORDRECITINGPARA_H
