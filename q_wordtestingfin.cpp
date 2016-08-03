#include "q_wordtestingfin.h"

Q_WordtestingFin::Q_WordtestingFin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
}

Q_WordtestingFin::~Q_WordtestingFin()
{

}

void Q_WordtestingFin::start(int score)
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(this);

	if (score < 60)
	{
		ui.label_Success->hide();
		ui.label_Failed->show();
	}
	else
	{
		ui.label_Success->show();
		ui.label_Failed->hide();
	}

	std::string sScore;
	int score1 = score;
	while (score1)
	{
		int p = score1 % 10;
		sScore = static_cast <char> (p + 48) + sScore;
		score1 /= 10;
	}
	
	ui.label_2->setText(QString::fromLocal8Bit(("欢迎使用千词斩，" + administration->getCurUserName() + "!").c_str()));
	if (score < 60)
	{
		sScore = "<html><head/><body><p>您的最后得分为：<span style="" color:#ff0000;"">" + sScore + "</span>/100</p></body></html>";
	}
	else
	{
		sScore = "<html><head/><body><p>您的最后得分为：<span style="" color:#00ff00;"">" + sScore + "</span>/100</p></body></html>";
	}

	ui.label_Score->setText(QString::fromLocal8Bit(sScore.c_str()));
}

void Q_WordtestingFin::slot_back()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);
}