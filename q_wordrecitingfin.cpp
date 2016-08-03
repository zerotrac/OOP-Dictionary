#include "q_wordrecitingfin.h"

Q_WordrecitingFin::Q_WordrecitingFin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QObject::connect(ui.button_Back, SIGNAL(clicked()), this, SLOT(slot_back()));
}

Q_WordrecitingFin::~Q_WordrecitingFin()
{

}

void Q_WordrecitingFin::start(std::string st, int x)
{
    //std::cout << "good" << std::endl;
    ui.label_2->setText(QString::fromLocal8Bit(("欢迎使用千词斩，" + st + "！").c_str()));
    ui.label_Mission->setText(QString::fromLocal8Bit(("您今日完成了背" + toString0(x) + "个单词的任务。").c_str()));
}

void Q_WordrecitingFin::slot_back()
{
    q_MainWindow->takeCentralWidget();
    q_MainWindow->setCentralWidget(q_Selection);
}
