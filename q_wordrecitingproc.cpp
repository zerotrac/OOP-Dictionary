#include "q_wordrecitingproc.h"

Q_WordrecitingProc::Q_WordrecitingProc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QObject::connect(ui.button_Abandon, SIGNAL(clicked()), this, SLOT(slot_back()));
    QObject::connect(ui.button_Yes, SIGNAL(clicked()), this, SLOT(slot_yes()));
    QObject::connect(ui.button_No, SIGNAL(clicked()), this, SLOT(slot_no()));
    QObject::connect(ui.button_Cancel, SIGNAL(clicked()), this, SLOT(slot_cancel()));
    QObject::connect(ui.button_Kill, SIGNAL(clicked()), this, SLOT(slot_kill()));
    QObject::connect(ui.button_Next, SIGNAL(clicked()), this, SLOT(slot_next()));
}

Q_WordrecitingProc::~Q_WordrecitingProc()
{

}

void Q_WordrecitingProc::start(Wordreciting *rhs_wordreciting, User *rhs_user)
{
    wordreciting = rhs_wordreciting;
    user = rhs_user;
    display();
}

void Q_WordrecitingProc::display()
{
    if (!wordreciting->isDailyCompleted())
    {
        std::string st;
        st = "较难词汇：" + toString0(wordreciting->getDailyCount(0)); ui.label_0->setText(QString::fromLocal8Bit(st.c_str()));
        st = "生疏词汇：" + toString0(wordreciting->getDailyCount(1)); ui.label_1->setText(QString::fromLocal8Bit(st.c_str()));
        st = "掌握词汇：" + toString0(wordreciting->getDailyCount(2)); ui.label_2->setText(QString::fromLocal8Bit(st.c_str()));

        Word *word = wordreciting->getCurWord();
        ui.label_Word->setText(QString(word->getName().c_str()));
        ui.label_Meaning->setText(QString(word->getMeaning(0).c_str()));
        ui.label_Meaning->hide();
        ui.label_Yes->hide();
        ui.label_No->hide();
        ui.label_kill->hide();
        ui.button_Yes->setEnabled(true);
        ui.button_No->setEnabled(true);
        ui.button_Next->setEnabled(false);
        buttonHide();
    }
    else
    {
        q_MainWindow->takeCentralWidget();
        q_MainWindow->setCentralWidget(q_WordrecitingFin);

        wordreciting->abandonDailyMission();
        user->output(wordreciting);
        q_WordrecitingFin->start(user->getUserName(), wordreciting->getDailyNumber());
    }
}

void Q_WordrecitingProc::buttonShow()
{
    ui.button_Cancel->setEnabled(true);
    ui.button_Kill->setEnabled(true);
}

void Q_WordrecitingProc::buttonHide()
{
    ui.button_Cancel->setEnabled(false);
    ui.button_Kill->setEnabled(false);
}

void Q_WordrecitingProc::abandon()
{
    wordreciting->abandonDailyMission();
    user->output(wordreciting);
}

void Q_WordrecitingProc::slot_back()
{
    this->setEnabled(false);
    q_WordrecitingRet->show();
}

void Q_WordrecitingProc::slot_yes()
{
    wordreciting->giveAnswer(1);

    ui.button_Yes->setEnabled(false);
    ui.button_No->setEnabled(false);
    ui.button_Next->setEnabled(true);
    ui.label_Yes->show();
    ui.label_Meaning->show();
    buttonShow();
}

void Q_WordrecitingProc::slot_no()
{
    wordreciting->giveAnswer(0);

    ui.button_Yes->setEnabled(false);
    ui.button_No->setEnabled(false);
    ui.button_Next->setEnabled(true);
    ui.label_No->show();
    ui.label_Meaning->show();
}

void Q_WordrecitingProc::slot_cancel()
{
    wordreciting->regret();
    ui.label_Yes->hide();
    ui.label_No->show();
    buttonHide();
}

void Q_WordrecitingProc::slot_kill()
{
    wordreciting->kill();
    ui.label_kill->show();
    buttonHide();
}

void Q_WordrecitingProc::slot_next()
{
    wordreciting->toNext();
    display();
}
