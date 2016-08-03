#include "q_login.h"

Q_Login::Q_Login(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label_ex3->hide();
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_Preparation()));
	QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_Interface()));
	QObject::connect(ui.line_Username, SIGNAL(textChanged(const QString &)), this, SLOT(slot_check1()));
	QObject::connect(ui.line_Password, SIGNAL(textChanged(const QString &)), this, SLOT(slot_check2()));
}

Q_Login::~Q_Login()
{

}

void Q_Login::clear()
{
	ui.line_Username->clear();
	ui.line_Password->clear();
	ui.label_ex3->hide();
}

void Q_Login::slot_Interface()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Interface);
}

void Q_Login::slot_check1()
{
	QString txt = ui.line_Username->text();
	ui.label_ex3->hide();
	if (txt.length() == 0)
	{
		ui.label_ex1->show();
	}
	else
	{
		ui.label_ex1->hide();
	}
}

void Q_Login::slot_check2()
{
	QString txt1 = ui.line_Password->text();
	ui.label_ex3->hide();
	if (txt1.length() == 0)
	{
		ui.label_ex2->show();
	}
	else
	{
		ui.label_ex2->hide();
	}
}

void Q_Login::slot_Preparation()
{
	if (ui.label_ex1->isHidden() && ui.label_ex2->isHidden())
	{
		std::string username = ui.line_Username->text().toStdString();
		std::string password = ui.line_Password->text().toStdString();
		int chk = administration->checkLogin(username, password);

		if (chk == 0)
		{
			ui.label_ex3->hide();
			this->setEnabled(false);
			q_LoginSuccess->show();
		}
		else
		{
			ui.label_ex3->show();
		}
	}
}