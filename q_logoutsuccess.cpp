#include "q_logoutsuccess.h"

Q_LogoutSuccess::Q_LogoutSuccess(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_logout()));
}

Q_LogoutSuccess::~Q_LogoutSuccess()
{

}

void Q_LogoutSuccess::slot_logout()
{
	this->close();
	q_Selection->setEnabled(true);
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Interface);
}