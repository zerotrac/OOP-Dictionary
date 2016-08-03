#include "q_selection.h"

Q_Selection::Q_Selection(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Logout, SIGNAL(clicked()), this, SLOT(slot_logout()));
	QObject::connect(ui.button_Wordsearching, SIGNAL(clicked()), this, SLOT(slot_wordsearching()));
	QObject::connect(ui.button_Wordtesting, SIGNAL(clicked()), this, SLOT(slot_wordtesting()));
	QObject::connect(ui.button_Wordreciting, SIGNAL(clicked()), this, SLOT(slot_wordreciting()));
	QObject::connect(ui.button_Textsearching, SIGNAL(clicked()), this, SLOT(slot_textsearching()));
}

Q_Selection::~Q_Selection()
{

}

void Q_Selection::start()
{
	ui.label_2->setText(QString::fromLocal8Bit(("欢迎使用千词斩，" + administration->getCurUserName() + "!").c_str()));
}

void Q_Selection::slot_logout()
{
	administration->logout();
	this->setEnabled(false);
	q_LogoutSuccess->show();
}

void Q_Selection::slot_wordsearching()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Wordsearching);
	q_Wordsearching->search_clear();
	q_Wordsearching->clear();
}

void Q_Selection::slot_wordtesting()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Wordtesting);
}

void Q_Selection::slot_wordreciting()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Wordreciting);
	q_Wordreciting->start(administration->getCurUser());
}

void Q_Selection::slot_textsearching()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Textsearching);
	q_Textsearching->init();
}