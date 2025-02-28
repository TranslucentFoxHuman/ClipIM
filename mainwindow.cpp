/*
 * ClipIM
 * Copyright (C) 2025 半狐 (半透明狐人間,TlFoxHuman,TranslucentFoxHuman)
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "var.h"
#include "aboutdialog.h"
#include <QString>
#include <QTimer>
#include <QClipboard>
#include <QShortcut>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(mode);

    QAction *action = new QAction(this);
    action->setShortcut(QKeySequence("Ctrl+Return"));
    connect(action, &QAction::triggered, this, &MainWindow::on_cpandcloseButton_clicked);
    this->addAction(action);

    switch (mode) {
        case 0:
            ui->lineEdit->setFocus();
        break;
        case 1:
            ui->plainTextEdit->setFocus();
        break;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->lineEdit->text());
    QTimer::singleShot(100, this, &MainWindow::close);
}


void MainWindow::on_cpandcloseButton_clicked()
{
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        MainWindow::on_lineEdit_returnPressed();
        break;
    case 1:
        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->setText(ui->plainTextEdit->toPlainText());
        QTimer::singleShot(100, this, &MainWindow::close);
        break;
    }
}


void MainWindow::on_copyButton_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        clipboard->setText(ui->lineEdit->text());
        break;
    case 1:
        clipboard->setText(ui->plainTextEdit->toPlainText());
        break;
    }
}

void MainWindow::on_actionAbout_triggered(){
    AboutDialog *abtdiag = new AboutDialog(this);
    abtdiag->show();
}

