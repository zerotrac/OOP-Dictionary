#include "q_interface.h"

Q_Interface::Q_Interface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Exit, SIGNAL(clicked()), this, SLOT(slot_Finished()));
	QObject::connect(ui.button_Register, SIGNAL(clicked()), this, SLOT(slot_Register()));
	QObject::connect(ui.button_Login, SIGNAL(clicked()), this, SLOT(slot_Login()));
}

Q_Interface::~Q_Interface()
{
	
}

void Q_Interface::slot_Finished()
{
	this->setEnabled(false);
	q_CheckExit->show();
}

void Q_Interface::slot_Killed()
{
	q_MainWindow->close();
}

void Q_Interface::slot_Register()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Register);
	q_Register->clear();
}

void Q_Interface::slot_Login()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Login);
	q_Login->clear();
}