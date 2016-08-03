#ifndef Q_WORDRECITINGPROC_H
#define Q_WORDRECITINGPROC_H

#include <QWidget>
#include "ui_q_wordrecitingproc.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_wordreciting.h"
#include "q_wordrecitingfin.h"
#include "q_wordrecitingret.h"

#include "Command/Wordreciting.h"
#include "Command/User.h"
#include "Command/Tostring.h"

class Q_WordrecitingProc : public QWidget
{
	Q_OBJECT

public:
	Q_WordrecitingProc(QWidget *parent = 0);
	~Q_WordrecitingProc();

public:
    OOP_Dictionary_Qt *q_MainWindow;
    Q_Wordreciting *q_Wordreciting;
    Q_WordrecitingRet *q_WordrecitingRet;
    Q_WordrecitingFin *q_WordrecitingFin;
    Wordreciting *wordreciting;
    User *user;

public:
    void start(Wordreciting *, User *);
    void display();
    void buttonShow();
    void buttonHide();
    void abandon();

public slots:
    void slot_back();
    void slot_yes();
    void slot_no();
    void slot_cancel();
    void slot_kill();
    void slot_next();

private:
	Ui::Q_WordrecitingProc ui;
};

#endif // Q_WORDRECITINGPROC_H
