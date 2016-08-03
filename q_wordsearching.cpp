#include "q_wordsearching.h"
#include <fstream>

Q_Wordsearching::Q_Wordsearching(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
	QObject::connect(ui.line_Search, SIGNAL(textChanged(const QString &)), this, SLOT(slot_prefix()));
	QObject::connect(ui.button_Search, SIGNAL(clicked()), this, SLOT(slot_precise()));
	QObject::connect(ui.button_Add1, SIGNAL(clicked()), this, SLOT(slot_add1()));
	QObject::connect(ui.button_Add2, SIGNAL(clicked()), this, SLOT(slot_add2()));
	QObject::connect(ui.button_Complete1, SIGNAL(clicked()), this, SLOT(slot_complete1()));
	QObject::connect(ui.button_Complete2, SIGNAL(clicked()), this, SLOT(slot_complete2()));
	QObject::connect(ui.button_Delete1, SIGNAL(clicked()), this, SLOT(slot_delete1()));
	QObject::connect(ui.button_Delete2, SIGNAL(clicked()), this, SLOT(slot_delete2()));
	QObject::connect(ui.button_History, SIGNAL(clicked()), this, SLOT(slot_history()));
}

Q_Wordsearching::~Q_Wordsearching()
{

}

void Q_Wordsearching::search_clear()
{
	ui.line_Search->clear();
}

void Q_Wordsearching::clear()
{
	ui.button_Complete1->hide();
	ui.button_Complete2->hide();
	ui.button_Add1->show(), ui.button_Add1->setEnabled(false);
	ui.button_Add2->show(), ui.button_Add2->setEnabled(false);
	ui.button_Delete1->setEnabled(false);
	ui.button_Delete2->setEnabled(false);
	ui.line_Sentence1->setEnabled(false);
	ui.line_Sentence2->setEnabled(false);

	ui.line_Prefix->clear();
	ui.line_Meaning->clear();
	ui.line_Sentence1->clear();
	ui.line_Sentence2->clear();

	word = nullptr;
	wordlist = nullptr;
}

void Q_Wordsearching::slot_back()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);
}

void Q_Wordsearching::slot_prefix()
{
	clear();

	std::string st = ui.line_Search->text().toStdString();
	wordlist = wordsearching->findPrefixWord(st);
	for (int i = 0; i < wordlist->size(); i++)
	{
		std::string name = wordlist->getWord(i)->getName();
		ui.line_Prefix->insertPlainText(QString(name.c_str()));
		if (i != wordlist->size() - 1) ui.line_Prefix->insertPlainText("\n");
	}
}

void Q_Wordsearching::slot_precise()
{
	slot_prefix();
	slot_display();
}

void Q_Wordsearching::slot_display()
{
	std::string st = ui.line_Search->text().toStdString();
	word = wordsearching->findPreciseWord(st);
	if (word == nullptr) return;

	std::string meaning = word->getMeaning(0);
	ui.line_Meaning->insertPlainText(QString(meaning.c_str()));
	
	int scount = word->getSentenceSize();
	if (scount == 0)
	{
		ui.button_Delete1->setEnabled(false);
		ui.button_Delete2->setEnabled(false);
	}
	if (scount == 1)
	{
		std::string sentence = word->getSentence(0);
		ui.line_Sentence1->insertPlainText(QString(sentence.c_str()));
		ui.button_Delete1->setEnabled(true);
		ui.button_Delete2->setEnabled(false);
	}
	if (scount == 2)
	{
		std::string sentence = word->getSentence(0);
		ui.line_Sentence1->insertPlainText(QString(sentence.c_str()));
		ui.button_Delete1->setEnabled(true);
		
		sentence = word->getSentence(1);
		ui.line_Sentence2->insertPlainText(QString(sentence.c_str()));
		ui.button_Delete2->setEnabled(true);
	}

	if (scount == 0)
	{
		ui.button_Add1->setEnabled(true);
		ui.button_Add2->setEnabled(true);
	}
	if (scount == 1)
	{
		ui.button_Add1->setEnabled(false);
		ui.button_Add2->setEnabled(true);
	}
	if (scount == 2)
	{
		ui.button_Add1->setEnabled(false);
		ui.button_Add2->setEnabled(false);
	}
}

void Q_Wordsearching::slot_history()
{
	clear(), search_clear();
	clear(), search_clear();
	
	wordlist = wordsearching->getHistory();
	for (int i = 0; i < wordlist->size(); i++)
	{
		std::string name = wordlist->getWord(i)->getName();
		ui.line_Prefix->insertPlainText(QString(name.c_str()));
		if (i != wordlist->size() - 1) ui.line_Prefix->insertPlainText("\n");
	}
}

void Q_Wordsearching::slot_add1()
{
	ui.button_Add1->hide();
	ui.button_Complete1->show();
	ui.line_Sentence1->setEnabled(true);
}

void Q_Wordsearching::slot_add2()
{
	ui.button_Add2->hide();
	ui.button_Complete2->show();
	ui.line_Sentence2->setEnabled(true);
}

void Q_Wordsearching::slot_complete1()
{
	ui.button_Add1->show();
	ui.button_Complete1->hide();
	std::string st = ui.line_Sentence1->toPlainText().toStdString();
	word->updateSentence(st);
	wordsearching->setdownSentence();

	slot_prefix();
	slot_display();
}

void Q_Wordsearching::slot_complete2()
{
	ui.button_Add2->show();
	ui.button_Complete2->hide();
	std::string st = ui.line_Sentence2->toPlainText().toStdString();
	word->updateSentence(st);
	wordsearching->setdownSentence();

	slot_prefix();
	slot_display();
}

void Q_Wordsearching::slot_delete1()
{
	word->deleteSentence(0);
	wordsearching->setdownSentence();

	slot_prefix();
	slot_display();
}

void Q_Wordsearching::slot_delete2()
{
	word->deleteSentence(1);
	wordsearching->setdownSentence();

	slot_prefix();
	slot_display();
}
