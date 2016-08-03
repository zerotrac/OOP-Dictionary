#include "q_wordrecitingpara.h"

Q_WordrecitingPara::Q_WordrecitingPara(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QObject::connect(ui.button_Start, SIGNAL(clicked()), this, SLOT(slot_start()));
    QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
    QObject::connect(ui.slider_Number, SIGNAL(valueChanged(int)), this, SLOT(slot_number()));
    QObject::connect(ui.slider_Proportion, SIGNAL(valueChanged(int)), this, SLOT(slot_proportion()));
}

Q_WordrecitingPara::~Q_WordrecitingPara()
{

}

void Q_WordrecitingPara::start(Wordreciting *rhs_wordreciting, User *rhs_user)
{
	wordreciting = rhs_wordreciting;
	user = rhs_user;

	if (wordreciting == user->getWordreciting(0)) ui.radio_cet4->setChecked(true);
	if (wordreciting == user->getWordreciting(1)) ui.radio_cet6->setChecked(true);
	if (wordreciting == user->getWordreciting(2)) ui.radio_toefl->setChecked(true);

    int x0 = wordreciting->getRandom();
    if (x0 == 0)
    {
        ui.check_Order->setChecked(true);
        ui.check_Random->setChecked(false);
    }
    else
    {
        ui.check_Order->setChecked(false);
        ui.check_Random->setChecked(true);
    }
    ui.radio_cet4->setEnabled(false);
    ui.radio_cet6->setEnabled(false);
    ui.radio_toefl->setEnabled(false);
    ui.check_Order->setEnabled(false);
    ui.check_Random->setEnabled(false);

    ui.slider_Number->setValue(wordreciting->getDailyNumber());
    ui.slider_Proportion->setValue(wordreciting->getProportion());
    changeValue();
}

void Q_WordrecitingPara::changeValue()
{
    int x1 = wordreciting->getDailyNumber();
    int x2 = wordreciting->getProportion();
    ui.line_Number->setText(QString(toString0(x1).c_str()));
    ui.line_Proportion->setText(QString((toString0(x2) + "%").c_str()));
}

void Q_WordrecitingPara::slot_start()
{
    q_MainWindow->takeCentralWidget();
    q_MainWindow->setCentralWidget(q_WordrecitingProc);
    wordreciting->startDailyMission();
    q_WordrecitingProc->start(wordreciting, user);
    q_WordrecitingProc->display();
}

void Q_WordrecitingPara::slot_back()
{
    q_MainWindow->takeCentralWidget();
    q_MainWindow->setCentralWidget(q_Wordreciting);
}

void Q_WordrecitingPara::slot_number()
{
    int x = ui.slider_Number->value();
    wordreciting->setDailyNumber(x);
    changeValue();
}

void Q_WordrecitingPara::slot_proportion()
{
    int x = ui.slider_Proportion->value();
    wordreciting->setProportion(x);
    changeValue();
}
