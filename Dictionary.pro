#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T23:29:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dictionary
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        oop_dictionary_qt.cpp \
    q_checkexit.cpp \
    q_interface.cpp \
    q_login.cpp \
    q_loginsuccess.cpp \
    q_logoutsuccess.cpp \
    q_register.cpp \
    q_registersuccess.cpp \
    q_selection.cpp \
    q_wordreciting.cpp \
    q_wordrecitingfin.cpp \
    q_wordrecitinginit.cpp \
    q_wordrecitingpara.cpp \
    q_wordrecitingproc.cpp \
    q_wordrecitingret.cpp \
    q_wordsearching.cpp \
    q_wordtesting.cpp \
    q_wordtestingfin.cpp \
    q_wordtestingproc.cpp \
    q_wordtestingret.cpp \
    Command/DailyWordreciting.cpp \
    Command/Strategy.cpp \
    Command/Textsearching.cpp \
    Command/Trie.cpp \
    Command/User.cpp \
    Command/Word.cpp \
    Command/Wordlist.cpp \
    Command/Wordreciting.cpp \
    Command/Wordsearching.cpp \
    Command/Wordtesting.cpp \
    Command/Administration.cpp \
    q_textsearching.cpp \
    Command/Tostring.cpp

HEADERS  += oop_dictionary_qt.h \
    headerFiles.h \
    q_checkexit.h \
    q_interface.h \
    q_login.h \
    q_loginsuccess.h \
    q_logoutsuccess.h \
    q_register.h \
    q_registersuccess.h \
    q_selection.h \
    q_wordreciting.h \
    q_wordrecitingfin.h \
    q_wordrecitinginit.h \
    q_wordrecitingpara.h \
    q_wordrecitingproc.h \
    q_wordrecitingret.h \
    q_wordsearching.h \
    q_wordtesting.h \
    q_wordtestingfin.h \
    q_wordtestingproc.h \
    q_wordtestingret.h \
    Command/DailyWordreciting.h \
    Command/Strategy.h \
    Command/Textsearching.h \
    Command/Trie.h \
    Command/User.h \
    Command/Word.h \
    Command/Wordlist.h \
    Command/Wordreciting.h \
    Command/Wordsearching.h \
    Command/Wordtesting.h \
    Command/Administration.h \
    q_textsearching.h \
    Command/Tostring.h

FORMS    += oop_dictionary_qt.ui \
    q_checkexit.ui \
    q_interface.ui \
    q_login.ui \
    q_loginsuccess.ui \
    q_logoutsuccess.ui \
    q_register.ui \
    q_registersuccess.ui \
    q_selection.ui \
    q_wordreciting.ui \
    q_wordrecitingfin.ui \
    q_wordrecitinginit.ui \
    q_wordrecitingpara.ui \
    q_wordrecitingproc.ui \
    q_wordrecitingret.ui \
    q_wordsearching.ui \
    q_wordtesting.ui \
    q_wordtestingfin.ui \
    q_wordtestingproc.ui \
    q_wordtestingret.ui \
    q_textsearching.ui

DISTFILES += \
    vocabulary/cet-4/cet-4.txt \
    vocabulary/cet-4/cet-4_meaning.txt \
    vocabulary/cet-4/cet-4_sentence.txt \
    vocabulary/cet-4/cet-4_word.txt \
    vocabulary/cet-6/cet-6.txt \
    vocabulary/cet-6/cet-6_meaning.txt \
    vocabulary/cet-6/cet-6_sentence.txt \
    vocabulary/cet-6/cet-6_word.txt \
    vocabulary/dictionary/dictionary.txt \
    vocabulary/dictionary/dictionary_history.txt \
    vocabulary/dictionary/dictionary_meaning.txt \
    vocabulary/dictionary/dictionary_sentence.txt \
    vocabulary/dictionary/dictionary_word.txt \
    vocabulary/toefl/toefl.txt \
    vocabulary/toefl/toefl_meaning.txt \
    vocabulary/toefl/toefl_sentence.txt \
    vocabulary/toefl/toefl_word.txt
