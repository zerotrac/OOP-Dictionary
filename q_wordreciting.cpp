#include "q_wordreciting.h"

Q_Wordreciting::Q_Wordreciting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
    QObject::connect(ui.button_CET4, SIGNAL(clicked()), this, SLOT(slot_choose0()));
    QObject::connect(ui.button_CET6, SIGNAL(clicked()), this, SLOT(slot_choose1()));
    QObject::connect(ui.button_TOEFL, SIGNAL(clicked()), this, SLOT(slot_choose2()));
}

Q_Wordreciting::~Q_Wordreciting()
{

}

void Q_Wordreciting::start(User *rhs_user)
{
	user = rhs_user;

	int a0 = user->getWordCount(0);
	int b0 = user->getWordCount(1);
	int c0 = user->getWordCount(2);

	int a1 = user->getPercent(0);
	int b1 = user->getPercent(1);
	int c1 = user->getPercent(2);

    ui.label_CET4_Count->setText(QString::fromLocal8Bit(("总单词数量：" + toString0(a0)).c_str()));
    ui.label_CET4_Progress->setText(QString::fromLocal8Bit(("进度：" + toString0(a1) + "%").c_str()));

    ui.label_CET6_Count->setText(QString::fromLocal8Bit(("总单词数量：" + toString0(b0)).c_str()));
    ui.label_CET6_Progress->setText(QString::fromLocal8Bit(("进度：" + toString0(b1) + "%").c_str()));

    ui.label_TOEFL_Count->setText(QString::fromLocal8Bit(("总单词数量：" + toString0(c0)).c_str()));
    ui.label_TOEFL_Progress->setText(QString::fromLocal8Bit(("进度：" + toString0(c1) + "%").c_str()));
}

void Q_Wordreciting::init()
{
	if (!wordreciting->ifStart())
	{
        this->setEnabled(false);
        q_WordrecitingInit->show();
        q_WordrecitingInit->start(wordreciting);
	}
    else
    {
        para();
    }
}

void Q_Wordreciting::para()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_WordrecitingPara);
    q_WordrecitingPara->start(wordreciting, user);
}

void Q_Wordreciting::slot_back()
{
    q_MainWindow->takeCentralWidget();
    q_MainWindow->setCentralWidget(q_Selection);
}

void Q_Wordreciting::slot_choose0()
{
	wordreciting = user->getWordreciting(0);
	init();
}

void Q_Wordreciting::slot_choose1()
{
	wordreciting = user->getWordreciting(1);
	init();
}

void Q_Wordreciting::slot_choose2()
{
	wordreciting = user->getWordreciting(2);
	init();
}


