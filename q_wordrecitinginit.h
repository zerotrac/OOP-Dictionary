#ifndef Q_WORDRECITINGINIT_H
#define Q_WORDRECITINGINIT_H

#include <QWidget>
#include "ui_q_wordrecitinginit.h"

#include "headerFiles.h"
#include "q_wordreciting.h"
#include "Command/Wordreciting.h"

class Q_WordrecitingInit : public QWidget
{
	Q_OBJECT

public:
	Q_WordrecitingInit(QWidget *parent = 0);
	~Q_WordrecitingInit();

public:
	Q_Wordreciting *q_Wordreciting;
	Wordreciting *wordreciting;

public:
	void start(Wordreciting *);

public slots:
	void slot_yes();

private:
	Ui::Q_WordrecitingInit ui;
};

#endif // Q_WORDRECITINGINIT_H
