#include "q_registersuccess.h"

Q_RegisterSuccess::Q_RegisterSuccess(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_register()));
}

Q_RegisterSuccess::~Q_RegisterSuccess()
{

}

void Q_RegisterSuccess::slot_register()
{
	this->close();
	q_Register->setEnabled(true);
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Interface);
}