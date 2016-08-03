#include "q_wordtesting.h"

Q_Wordtesting::Q_Wordtesting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
	QObject::connect(ui.button_Start, SIGNAL(clicked()), this, SLOT(slot_start()));
}

Q_Wordtesting::~Q_Wordtesting()
{

}

void Q_Wordtesting::slot_back()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);
}

void Q_Wordtesting::slot_start()
{
	if (ui.radio_cet4->isChecked()) q_WordtestingProc->wordtesting = new Wordtesting(wordlist_cet4);
	if (ui.radio_cet6->isChecked()) q_WordtestingProc->wordtesting = new Wordtesting(wordlist_cet6);
	if (ui.radio_toefl->isChecked()) q_WordtestingProc->wordtesting = new Wordtesting(wordlist_toefl);
	q_WordtestingProc->wordtesting->generateQuery();
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_WordtestingProc);
	q_WordtestingProc->display();
}