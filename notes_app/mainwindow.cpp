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
    saveNotes = "";
    ui->plainTextEdit->setPlainText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    saveNotes = fileName;
    if (!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(this, "..", "file not open");
        return;
    }

    QTextStream text(&file);
    QString notes = text.readAll();
    ui->plainTextEdit->setPlainText(notes);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = "";
    if (saveNotes == ""){
        fileName = QFileDialog::getSaveFileName(this, "Open the file");
    }
    else{
        fileName = saveNotes;
    }

    QFile file(fileName);
    if (!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(this, "..", "file not open");
        return;
    }

    QTextStream text(&file);
    QString notes = ui->plainTextEdit->toPlainText();
    text << notes;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open the file");
    QFile file(fileName);
    saveNotes = fileName;
    if (!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::warning(this, "..", "file not open");
        return;
    }

    QTextStream text(&file);
    QString notes = ui->plainTextEdit->toPlainText();
    text << notes;
    file.flush();
    file.close();

}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox::information(this, "Exit", "Would you like to exit?");
}

