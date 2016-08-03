#ifndef Q_LOGOUTSUCCESS_H
#define Q_LOGOUTSUCCESS_H

#include <QWidget>
#include "ui_q_logoutsuccess.h"

#include "headerFiles.h"
#include "oop_dictionary_qt.h"
#include "q_selection.h"
#include "q_interface.h"

class Q_LogoutSuccess : public QWidget
{
	Q_OBJECT

public:
	Q_LogoutSuccess(QWidget *parent = 0);
	~Q_LogoutSuccess();

public:
	OOP_Dictionary_Qt *q_MainWindow;
	Q_Selection *q_Selection;
	Q_Interface *q_Interface;

public slots:
	void slot_logout();

private:
	Ui::Q_LogoutSuccess ui;
};

#endif // Q_LOGOUTSUCCESS_H
