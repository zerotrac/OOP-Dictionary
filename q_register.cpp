#include "q_register.h"
#include <Qstring>

Q_Register::Q_Register(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.label_ex3->hide();
	ui.label_ex4->hide();
	QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_Preparation()));
	QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_Interface()));
	QObject::connect(ui.line_Username, SIGNAL(textChanged(const QString &)), this, SLOT(slot_check1()));
	QObject::connect(ui.line_Password, SIGNAL(textChanged(const QString &)), this, SLOT(slot_check2()));
	QObject::connect(ui.line_ConfirmPassword, SIGNAL(textChanged(const QString &)), this, SLOT(slot_check3()));
}

Q_Register::~Q_Register()
{

}

void Q_Register::clear()
{
	ui.line_Username->clear();
	ui.line_Password->clear();
	ui.line_ConfirmPassword->clear();
}

void Q_Register::slot_Interface()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Interface);
}

void Q_Register::slot_check1()
{
	QString txt = ui.line_Username->text();
	ui.label_ex4->hide();
	if (txt.length() == 0)
	{
		ui.label_ex1->show();
	}
	else
	{
		ui.label_ex1->hide();
	}
}

void Q_Register::slot_check2()
{
	QString txt1 = ui.line_Password->text();
	QString txt2 = ui.line_ConfirmPassword->text();
	if (txt1.length() == 0)
	{
		ui.label_ex2->show();
	}
	else
	{
		ui.label_ex2->hide();
	}
	if (txt1 != txt2)
	{
		ui.label_ex3->show();
	}
	else
	{
		ui.label_ex3->hide();
	}
}

void Q_Register::slot_check3()
{
	QString txt1 = ui.line_Password->text();
	QString txt2 = ui.line_ConfirmPassword->text();
	if (txt1 != txt2)
	{
		ui.label_ex3->show();
	}
	else
	{
		ui.label_ex3->hide();
	}
}

void Q_Register::slot_Preparation()
{
    std::string username = ui.line_Username->text().toStdString();
    std::string password = ui.line_Password->text().toStdString();
	if (administration->findUserName(username) != nullptr)
	{
		ui.label_ex4->show();
	}
	else
	{
		ui.label_ex4->hide();
	}

	if (ui.label_ex1->isHidden() && ui.label_ex2->isHidden() && ui.label_ex3->isHidden() && ui.label_ex4->isHidden())
	{
		administration->addUser(new User(username, password));
		this->setEnabled(false);
		q_RegisterSuccess->show();
	}
}
