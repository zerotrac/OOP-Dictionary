#include "q_wordtestingret.h"

Q_WordtestingRet::Q_WordtestingRet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_yes()));
	QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_no()));
}

Q_WordtestingRet::~Q_WordtestingRet()
{

}

void Q_WordtestingRet::slot_yes()
{
	this->close();
	q_WordtestingProc->setEnabled(true);
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);

	q_WordtestingProc->del();
}

void Q_WordtestingRet::slot_no()
{
	this->close();
	q_WordtestingProc->setEnabled(true);
}