#include "q_wordrecitinginit.h"

Q_WordrecitingInit::Q_WordrecitingInit(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_yes()));
}

Q_WordrecitingInit::~Q_WordrecitingInit()
{

}

void Q_WordrecitingInit::start(Wordreciting *rhs_wordreciting)
{
    wordreciting = rhs_wordreciting;
    ui.radio_Order->setChecked(true);
}

void Q_WordrecitingInit::slot_yes()
{
	if (ui.radio_Order->isChecked())
	{
		wordreciting->setRandom(0);
	}
	else
	{
		wordreciting->setRandom(1);
	}
	wordreciting->start();

    this->close();
    q_Wordreciting->setEnabled(true);
    q_Wordreciting->para();
}
