#include "q_wordtestingproc.h"

Q_WordtestingProc::Q_WordtestingProc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Submit, SIGNAL(clicked()), this, SLOT(slot_submit()));
	QObject::connect(ui.button_Next, SIGNAL(clicked()), this, SLOT(slot_tonext()));
	QObject::connect(ui.button_Abandon, SIGNAL(clicked()), this, SLOT(slot_abandon()));
}

Q_WordtestingProc::~Q_WordtestingProc()
{

}

void Q_WordtestingProc::display()
{
	ui.label_A_F->hide();
	ui.label_A_T->hide();
	ui.label_B_F->hide();
	ui.label_B_T->hide();
	ui.label_C_F->hide();
	ui.label_C_T->hide();
	ui.label_D_F->hide();
	ui.label_D_T->hide();
	
	int curID = wordtesting->getLabel() + 1;
	int cnt = wordtesting->getQueryCount();
	int score = wordtesting->getScore();

	std::string sID = "";
	std::string sWord = "";
	std::string sScore = "";
	if (!score) sScore = "0";

	while (cnt)
	{
		int p = cnt % 10;
		sID = static_cast <char> (p + 48) + sID;
		cnt /= 10;
	}
	sID = "/" + sID;
	while (curID)
	{
		int p = curID % 10;
		sID = static_cast <char> (p + 48) + sID;
		sWord = static_cast <char> (p + 48) + sWord;
		curID /= 10;
	}
	while (score)
	{
		int p = score % 10;
		sScore = static_cast <char> (p + 48) + sScore;
		score /= 10;
	}

	sID = "当前题号：" + sID;
	sWord = sWord + ". " + wordtesting->getCurWord()->getName();
	if (wordtesting->getScore() < 60)
	{
		sScore = "<html><head/><body><p>当前分数：<span style="" color:#ff0000;"">" + sScore + "</span>/100</p></body></html>";
	}
	else
	{
		sScore = "<html><head/><body><p>当前分数：<span style="" color:#00ff00;"">" + sScore + "</span>/100</p></body></html>";
	}
	
	ui.label_ID->setText(QString::fromLocal8Bit(sID.c_str()));
	ui.label_Word->setText(sWord.c_str());
	ui.label_Score->setText(QString::fromLocal8Bit(sScore.c_str()));
	
	ui.radio_A->setText(("A. " + wordtesting->getQuery(0)).c_str());
	ui.radio_B->setText(("B. " + wordtesting->getQuery(1)).c_str());
	ui.radio_C->setText(("C. " + wordtesting->getQuery(2)).c_str());
	ui.radio_D->setText(("D. " + wordtesting->getQuery(3)).c_str());

	ui.radio_A->setEnabled(true);
	ui.radio_B->setEnabled(true);
	ui.radio_C->setEnabled(true);
	ui.radio_D->setEnabled(true);
	ui.radio_A->setChecked(true);
	ui.button_Submit->setEnabled(true);
	ui.button_Next->setEnabled(false);
}

void Q_WordtestingProc::del()
{
	delete wordtesting;
}

void Q_WordtestingProc::slot_submit()
{
	int answer = 0;
	if (ui.radio_A->isChecked()) answer = 0;
	if (ui.radio_B->isChecked()) answer = 1;
	if (ui.radio_C->isChecked()) answer = 2;
	if (ui.radio_D->isChecked()) answer = 3;
	wordtesting->giveAnswer(answer);

	int correctAns = wordtesting->getAnswer();
	if (correctAns == 0) ui.label_A_T->show();
	if (correctAns == 1) ui.label_B_T->show();
	if (correctAns == 2) ui.label_C_T->show();
	if (correctAns == 3) ui.label_D_T->show();
	
	if (answer != correctAns)
	{
		if (answer == 0) ui.label_A_F->show();
		if (answer == 1) ui.label_B_F->show();
		if (answer == 2) ui.label_C_F->show();
		if (answer == 3) ui.label_D_F->show();
	}

	ui.radio_A->setEnabled(false);
	ui.radio_B->setEnabled(false);
	ui.radio_C->setEnabled(false);
	ui.radio_D->setEnabled(false);
	ui.button_Submit->setEnabled(false);
	ui.button_Next->setEnabled(true);
}

void Q_WordtestingProc::slot_tonext()
{
	wordtesting->toNext();
	if (!wordtesting->isFinished())
	{
		display();
	}
	else
	{
		q_WordtestingFin->start(wordtesting->getScore());
		del();
	}
}

void Q_WordtestingProc::slot_abandon()
{
	this->setEnabled(false);
	q_WordtestingRet->show();
}