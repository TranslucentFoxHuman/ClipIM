#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "var.h"
#include <QString>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->versionLabel->setText(QString::fromStdString(version));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
