#include "q_checkexit.h"

Q_CheckExit::Q_CheckExit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_ChooseYes()));
	QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_ChooseNo()));
}

Q_CheckExit::~Q_CheckExit()
{

}

void Q_CheckExit::slot_ChooseYes()
{
	this->close();
	q_MainWindow->close();
}

void Q_CheckExit::slot_ChooseNo()
{
	this->close();
	q_Interface->setEnabled(true);
}