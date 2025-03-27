#include "exit.h"
#include "ui_exit.h"
#include <QMessageBox>
#include <QFile>

exit::exit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::exit)
{
    ui->setupUi(this);
}

exit::~exit()
{
    delete ui;
}

void exit::on_pushButton_clicked()
{
    this->close();
}


void exit::on_pushButton_2_clicked()
{
    qApp->exit();
}

