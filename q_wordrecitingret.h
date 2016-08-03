#ifndef Q_WORDRECITINGRET_H
#define Q_WORDRECITINGRET_H

#include <QWidget>
#include "ui_q_wordrecitingret.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_wordrecitingProc.h"
#include "q_selection.h"

class Q_WordrecitingRet : public QWidget
{
	Q_OBJECT

public:
	Q_WordrecitingRet(QWidget *parent = 0);
	~Q_WordrecitingRet();

public:
    OOP_Dictionary_Qt *q_MainWindow;
    Q_WordrecitingProc *q_WordrecitingProc;
    Q_Selection *q_Selection;

public slots:
    void slot_yes();
    void slot_no();

private:
	Ui::Q_WordrecitingRet ui;
};

#endif // Q_WORDRECITINGRET_H
