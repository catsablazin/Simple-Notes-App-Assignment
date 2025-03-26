#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    //QMessageBox::information(this, "Open", "Would you like to open a file?");
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    if (!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(this, "..", "file not open");
        return;
    }
    //(&file);
    //QPlainTextEdit;
    QTextStream text(&file);
    QString notes = text.readAll();
    ui->plainTextEdit->setPlainText(notes);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this, "Save", "Would you like to save?");
}


void MainWindow::on_actionSave_as_triggered()
{
    QMessageBox::information(this, "Save as", "Would you like to save as?");
}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox::information(this, "Exit", "Would you like to exit?");
}

