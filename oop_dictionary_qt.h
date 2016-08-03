#ifndef OOP_DICTIONARY_QT_H
#define OOP_DICTIONARY_QT_H

#include <QtWidgets/QMainWindow>
#include "ui_oop_dictionary_qt.h"

class OOP_Dictionary_Qt : public QMainWindow
{
	Q_OBJECT

public:
	OOP_Dictionary_Qt(QWidget *parent = 0);
	~OOP_Dictionary_Qt();

private:
	Ui::OOP_Dictionary_QtClass ui;
};

#endif // OOP_DICTIONARY_QT_H
