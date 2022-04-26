#include "grapfdialog.h"
#include "ui_grapfdialog.h"

GrapfDialog::GrapfDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GrapfDialog)
{
    ui->setupUi(this);
}

GrapfDialog::~GrapfDialog()
{
    delete ui;
}



