#include "oop_dictionary_qt.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

#include "Q_Interface.h"
#include "Q_Checkexit.h"
#include "Q_Register.h"
#include "Q_RegisterSuccess.h"
#include "Q_Login.h"
#include "Q_LoginSuccess.h"
#include "Q_Selection.h"
#include "Q_Wordsearching.h"
#include "Q_Wordtesting.h"
#include "Q_WordtestingProc.h"
#include "Q_WordtestingRet.h"
#include "Q_WordtestingFin.h"
#include "Q_Textsearching.h"
#include "Q_Wordreciting.h"
#include "Q_WordrecitingInit.h"
#include "Q_WordrecitingPara.h"
#include "Q_WordrecitingProc.h"
#include "Q_WordrecitingRet.h"
#include "Q_WordrecitingFin.h"

#include "Command/Administration.h"

#include <ctime>
#include <iostream>
#include <fstream>
#include "qdir.h"

int main(int argc, char *argv[])
{
	srand(unsigned(time(0)));

	QApplication a(argc, argv);

#ifdef __APPLE__
    QString pathApp = QCoreApplication::applicationDirPath();
    std::string sApp = pathApp.toStdString();
    int t = sApp.find("Dictionary.app");
    sApp.resize(t - 1);
    QDir::setCurrent(QString(sApp.c_str()));
    QString path2 = QDir::currentPath();
    //QMessageBox::warning(0,"PATH",path2,QMessageBox::Yes);//查看路径
#endif


    Wordlist *wordlist_Dictionary = new Wordlist("Vocabulary/dictionary/dictionary_word.txt",
                                                 "Vocabulary/dictionary/dictionary_meaning.txt",
                                                 "Vocabulary/dictionary/dictionary_sentence.txt");
    Wordlist *wordlist_cet4 = new Wordlist("Vocabulary/cet-4/cet-4_word.txt",
                                           "Vocabulary/cet-4/cet-4_meaning.txt",
                                           "Vocabulary/cet-4/cet-4_sentence.txt");
    Wordlist *wordlist_cet6 = new Wordlist("Vocabulary/cet-6/cet-6_word.txt",
                                           "Vocabulary/cet-6/cet-6_meaning.txt",
                                           "Vocabulary/cet-6/cet-6_sentence.txt");
    Wordlist *wordlist_toefl = new Wordlist("Vocabulary/toefl/toefl_word.txt",
                                            "Vocabulary/toefl/toefl_meaning.txt",
                                            "Vocabulary/toefl/toefl_sentence.txt");

    Wordsearching *wordsearching = new Wordsearching(wordlist_Dictionary);
    wordsearching->setupHistory();

	OOP_Dictionary_Qt *q_MainWindow = new OOP_Dictionary_Qt();
	q_MainWindow->show();

    Q_Interface *q_Interface = new Q_Interface();
	q_Interface->q_MainWindow = q_MainWindow;

	Q_CheckExit *q_CheckExit = new Q_CheckExit();
	q_CheckExit->q_Interface = q_Interface;
	q_CheckExit->q_MainWindow = q_MainWindow;
	q_Interface->q_CheckExit = q_CheckExit;

    Administration *adminstration = new Administration();
	adminstration->wordlist_cet4 = wordlist_cet4;
	adminstration->wordlist_cet6 = wordlist_cet6;
	adminstration->wordlist_toefl = wordlist_toefl;

	Q_Register *q_Register = new Q_Register();
	q_Register->q_MainWindow = q_MainWindow;
	q_Register->q_Interface = q_Interface;
    q_Register->administration = adminstration;
	q_Interface->q_Register = q_Register;

	Q_RegisterSuccess *q_RegisterSuccess = new Q_RegisterSuccess();
	q_RegisterSuccess->q_MainWindow = q_MainWindow;
	q_RegisterSuccess->q_Interface = q_Interface;
	q_RegisterSuccess->q_Register = q_Register;
	q_Register->q_RegisterSuccess = q_RegisterSuccess;

	Q_Login *q_Login = new Q_Login();
	q_Login->q_MainWindow = q_MainWindow;
	q_Login->q_Interface = q_Interface;
    q_Login->administration = adminstration;
	q_Interface->q_Login = q_Login;

	Q_LoginSuccess *q_LoginSuccess = new Q_LoginSuccess();
	q_LoginSuccess->q_MainWindow = q_MainWindow;
	q_LoginSuccess->q_Login = q_Login;
	q_Login->q_LoginSuccess = q_LoginSuccess;

	Q_Selection *q_Selection = new Q_Selection();
	q_Selection->q_MainWindow = q_MainWindow;
	q_Selection->q_Interface = q_Interface;
	q_Selection->administration = adminstration;
	q_LoginSuccess->q_Selection = q_Selection;

	Q_LogoutSuccess *q_LogoutSuccess = new Q_LogoutSuccess();
	q_LogoutSuccess->q_MainWindow = q_MainWindow;
	q_LogoutSuccess->q_Selection = q_Selection;
	q_LogoutSuccess->q_Interface = q_Interface;
	q_Selection->q_LogoutSuccess = q_LogoutSuccess;

	Q_Wordsearching *q_Wordsearching = new Q_Wordsearching();
	q_Wordsearching->q_MainWindow = q_MainWindow;
	q_Wordsearching->q_Selection = q_Selection;
	q_Wordsearching->wordsearching = wordsearching;
	q_Selection->q_Wordsearching = q_Wordsearching;
	
	Q_Wordtesting *q_Wordtesting = new Q_Wordtesting();
	q_Wordtesting->q_MainWindow = q_MainWindow;
	q_Wordtesting->q_Selection = q_Selection;
	q_Wordtesting->wordlist_cet4 = wordlist_cet4;
	q_Wordtesting->wordlist_cet6 = wordlist_cet6;
	q_Wordtesting->wordlist_toefl = wordlist_toefl;
	q_Selection->q_Wordtesting = q_Wordtesting;

	Q_WordtestingProc *q_WordtestingProc = new Q_WordtestingProc();
	q_WordtestingProc->q_MainWindow = q_MainWindow;
	q_WordtestingProc->q_Wordtesting = q_Wordtesting;
	q_Wordtesting->q_WordtestingProc = q_WordtestingProc;
	
	Q_WordtestingRet *q_WordtestingRet = new Q_WordtestingRet();
	q_WordtestingRet->q_MainWindow = q_MainWindow;
	q_WordtestingRet->q_Selection = q_Selection;
	q_WordtestingRet->q_WordtestingProc = q_WordtestingProc;
	q_WordtestingProc->q_WordtestingRet = q_WordtestingRet;

	Q_WordtestingFin *q_WordtestingFin = new Q_WordtestingFin();
	q_WordtestingFin->q_MainWindow = q_MainWindow;
	q_WordtestingFin->q_Selection = q_Selection;
	q_WordtestingFin->q_WordtestingProc = q_WordtestingProc;
	q_WordtestingFin->administration = adminstration;
	q_WordtestingProc->q_WordtestingFin = q_WordtestingFin;
	
	Q_Textsearching *q_Textsearching = new Q_Textsearching();
	q_Textsearching->q_MainWindow = q_MainWindow;
	q_Textsearching->q_Selection = q_Selection;
	q_Textsearching->wordlist_cet4 = wordlist_cet4;
	q_Textsearching->wordlist_cet6 = wordlist_cet6;
	q_Textsearching->wordlist_toefl = wordlist_toefl;
	q_Selection->q_Textsearching = q_Textsearching;
    
	Q_Wordreciting *q_Wordreciting = new Q_Wordreciting();
	q_Wordreciting->q_MainWindow = q_MainWindow;
	q_Wordreciting->q_Selection = q_Selection;
	q_Selection->q_Wordreciting = q_Wordreciting;

	Q_WordrecitingInit *q_WordrecitingInit = new Q_WordrecitingInit();
	q_WordrecitingInit->q_Wordreciting = q_Wordreciting;
	q_Wordreciting->q_WordrecitingInit = q_WordrecitingInit;

	Q_WordrecitingPara *q_WordrecitingPara = new Q_WordrecitingPara();
    q_WordrecitingPara->q_MainWindow = q_MainWindow;
    q_WordrecitingPara->q_Wordreciting = q_Wordreciting;
    q_Wordreciting->q_WordrecitingPara = q_WordrecitingPara;

    Q_WordrecitingProc *q_WordrecitingProc = new Q_WordrecitingProc();
    q_WordrecitingProc->q_MainWindow = q_MainWindow;
    q_WordrecitingProc->q_Wordreciting = q_Wordreciting;
    q_WordrecitingPara->q_WordrecitingProc = q_WordrecitingProc;

    Q_WordrecitingRet *q_WordrecitingRet = new Q_WordrecitingRet();
    q_WordrecitingRet->q_MainWindow = q_MainWindow;
    q_WordrecitingRet->q_Selection = q_Selection;
    q_WordrecitingRet->q_WordrecitingProc = q_WordrecitingProc;
    q_WordrecitingProc->q_WordrecitingRet = q_WordrecitingRet;

    Q_WordrecitingFin *q_WordrecitingFin = new Q_WordrecitingFin();
    q_WordrecitingFin->q_MainWindow = q_MainWindow;
    q_WordrecitingFin->q_Selection = q_Selection;
    q_WordrecitingProc->q_WordrecitingFin = q_WordrecitingFin;
	q_MainWindow->setCentralWidget(q_Interface);

	return a.exec();
}
