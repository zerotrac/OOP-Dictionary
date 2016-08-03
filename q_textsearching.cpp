#include "q_textsearching.h"

Q_Textsearching::Q_Textsearching(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
	QObject::connect(ui.button_Search, SIGNAL(clicked()), this, SLOT(slot_search()));
}

Q_Textsearching::~Q_Textsearching()
{

}

void Q_Textsearching::init()
{
	ui.line_Text->clear();
	ui.radio_cet4->setChecked(true);
	ui.tableWidget->clear();
	ui.tableWidget->setColumnCount(2);
	ui.tableWidget->setRowCount(1);
	ui.tableWidget->setColumnWidth(0, 75);
	ui.tableWidget->setColumnWidth(1, 150);

	QStringList header;
	header << QString::fromLocal8Bit("单词") << QString::fromLocal8Bit("解释");
	ui.tableWidget->setHorizontalHeaderLabels(header);

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止编辑
}

void Q_Textsearching::slot_back()
{
	q_MainWindow->takeCentralWidget();
	q_MainWindow->setCentralWidget(q_Selection);
}

void Q_Textsearching::slot_search()
{
	std::string st = ui.line_Text->toPlainText().toStdString();
	textsearching = new Textsearching();
	Wordlist *wordlist;
	
	if (ui.radio_cet4->isChecked())
	{
		wordlist = textsearching->search(st, wordlist_cet4);
	}
	if (ui.radio_cet6->isChecked())
	{
		wordlist = textsearching->search(st, wordlist_cet6);
	}
	if (ui.radio_toefl->isChecked())
	{
		wordlist = textsearching->search(st, wordlist_toefl);
	}

	ui.tableWidget->clearContents();
	ui.tableWidget->setRowCount(wordlist->size());
	for (int i = 0; i < wordlist->size(); i++)
	{
		Word *word = wordlist->getWord(i);
		std::string name = word->getName();
		std::string meaning = word->getMeaning(0);

		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(name.c_str()));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(meaning.c_str()));
	}

	delete textsearching;
	delete wordlist;
}