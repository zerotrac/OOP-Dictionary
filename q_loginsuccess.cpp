#include "q_loginsuccess.h"

Q_LoginSuccess::Q_LoginSuccess(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_login()));
}

Q_LoginSuccess::~Q_LoginSuccess()
{

}

void Q_LoginSuccess::slot_login()
{
	this->close();
	q_Login->setEnabled(true);
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);
	q_Selection->start();
}