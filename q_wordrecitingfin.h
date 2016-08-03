#ifndef Q_WORDRECITINGFIN_H
#define Q_WORDRECITINGFIN_H

#include <QWidget>
#include "ui_q_wordrecitingfin.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "Command/Tostring.h"

class Q_WordrecitingFin : public QWidget
{
	Q_OBJECT

public:
	Q_WordrecitingFin(QWidget *parent = 0);
	~Q_WordrecitingFin();

public:
    OOP_Dictionary_Qt *q_MainWindow;
    Q_Selection *q_Selection;

public:
    void start(std::string, int);

public slots:
    void slot_back();

private:
	Ui::Q_WordrecitingFin ui;
};

#endif // Q_WORDRECITINGFIN_H
