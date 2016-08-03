#include "q_wordrecitingret.h"

Q_WordrecitingRet::Q_WordrecitingRet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_yes()));
    QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_no()));
}

Q_WordrecitingRet::~Q_WordrecitingRet()
{

}

void Q_WordrecitingRet::slot_yes()
{
    this->hide();
    q_WordrecitingProc->setEnabled(true);
    q_WordrecitingProc->abandon();
    q_MainWindow->takeCentralWidget();
    q_MainWindow->setCentralWidget(q_Selection);
}

void Q_WordrecitingRet::slot_no()
{
    this->hide();
    q_WordrecitingProc->setEnabled(true);
}
