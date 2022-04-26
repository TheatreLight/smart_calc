#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rpn.h"
#include "plot/qcustomplot.h"
#include "credit.h"

#include <map>

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

bool is_res = false;
bool is_brscket_open = false;
int bracket_count = 0;
double var_x = NAN;
bool isAnnuity = true;


void MainWindow::on_pushButton_10_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("0");
}

void MainWindow::on_pushButton_11_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert(".");
}

void MainWindow::on_pushButton_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("1");
}

void MainWindow::on_pushButton_6_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("2");
}

void MainWindow::on_pushButton_9_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("3");
}

void MainWindow::on_pushButton_2_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("4");
}

void MainWindow::on_pushButton_5_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("5");
}

void MainWindow::on_pushButton_8_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("6");
}

void MainWindow::on_pushButton_3_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("7");
}

void MainWindow::on_pushButton_4_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("8");
}

void MainWindow::on_pushButton_7_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("9");
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->lineEdit->clear();
    is_brscket_open = false;
}


void MainWindow::on_pushButton_12_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("sin ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_15_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("cos ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_18_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("tan ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_13_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("asin ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_16_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("acos ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_19_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("atan ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_14_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("sqrt ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_17_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("log ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_20_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("ln ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->lineEdit->insert(" mod ");

}


void MainWindow::on_pushButton_29_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert(" ( ");
    is_brscket_open = true;
    bracket_count++;
}


void MainWindow::on_pushButton_30_clicked()
{
    if (is_brscket_open) {
    ui->lineEdit->insert(" ) ");
    bracket_count--;
    if (bracket_count <= 0)
        is_brscket_open = false;
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->lineEdit->insert(" + ");

}


void MainWindow::on_pushButton_24_clicked()
{
    ui->lineEdit->insert(" - ");

}


void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit->insert(" * ");

}


void MainWindow::on_pushButton_26_clicked()
{
    ui->lineEdit->insert(" / ");

}


void MainWindow::on_pushButton_22_clicked()
{
    ui->lineEdit->insert(" ^ ");

}


void MainWindow::on_pushButton_27_clicked()
{
//    qDebug() << is_brscket_open;
//    if (!is_brscket_open) {
        is_res = true;
        QString str = ui->lineEdit->text();
        QByteArray arr = str.toLatin1();
        char *inp_str = arr.data();
        QString x_str = ui->lineEdit_2->text();

        if (x_str != "\0")
            var_x = x_str.toDouble();

        char *str1 = (char*)calloc(256, sizeof(char));
        if (!input(str1, inp_str)) {
            ui->lineEdit->setText("ERROR");
            free(str1);
        } else {

        char *dst = (char*)calloc(256, sizeof(char));
        get_rpn(str1, dst);
        free(str1);
        double result = rpn_calculate(dst, var_x);
        free(dst);

        QString new_str;
        new_str = QString("%1").arg(result, 0, 'g', 12);
        ui->lineEdit->setText(new_str);
        }

}


void MainWindow::on_lineEdit_returnPressed()
{
    is_res = true;
    QString str = ui->lineEdit->text();
    QByteArray arr = str.toLatin1();
    char *inp_str = arr.data();
    QString x_str = ui->lineEdit_2->text();

    if (x_str != "\0")
        var_x = x_str.toDouble();

    char *str1 = (char*)calloc(256, sizeof(char));
    if (!input(str1, inp_str)) {
        ui->lineEdit->setText("ERROR");
        free(str1);
    } else {

    char *dst = (char*)calloc(256, sizeof(char));
    get_rpn(str1, dst);
    free(str1);
    double result = rpn_calculate(dst, var_x);
    free(dst);

    QString new_str;
    new_str = QString("%1").arg(result, 0, 'g', 12);
    ui->lineEdit->setText(new_str);
    }

}

void MainWindow::on_pushButton_32_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert("x");

}

void MainWindow::on_pushButton_31_clicked()
{
    if (is_res) {
        ui->lineEdit->clear();
        is_res = false;
    }
    ui->lineEdit->insert(" -");
}




void MainWindow::on_pushButton_33_clicked()
{
    ui->widget->clearGraphs();

    QString str = ui->lineEdit_3->text();
    QByteArray arr = str.toLatin1();
    char *inp_str = arr.data();

    QString str1 = ui->lineEdit_4->text();
    QString str2 = ui->lineEdit_6->text();
    QString str3 = ui->lineEdit_5->text();
    QString str4 = ui->lineEdit_7->text();

    double xBegin, xEnd, h, X, rangeX, rangeY;
    //int N;
    QVector<double> x, y;
    h = 0.1;
    xBegin = str1.toDouble();
    xEnd = str2.toDouble();
    rangeX = str3.toDouble();
    rangeY = str4.toDouble();

    ui->widget->xAxis->setRange(-1*rangeX, rangeX);
    ui->widget->yAxis->setRange(-1*rangeY, rangeY);

    for (X = xBegin; X <= xEnd; X += h) {
        x.push_back(X);
        y.push_back(graph_build(X, inp_str));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}


void MainWindow::on_pushButton_34_clicked()
{
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->widget->clearGraphs();
    ui->widget->replot();
}


void MainWindow::on_pushButton_35_clicked()
{
    QString str_amount = ui->lineEdit_10->text();
    double credit_amount = str_amount.toDouble();
    QString str_term = ui->lineEdit_9->text();
    int credit_term = str_term.toInt();
    QString str_rate = ui->lineEdit_8->text();
    double interest_rate = str_rate.toDouble();

    if (isAnnuity) {
        double monthly_fee = monthPay(credit_amount, interest_rate, credit_term);
        QString new_str;
        new_str = QString("%1").arg(monthly_fee, 0, 'f', 2);
        ui->lineEdit_11->setText(new_str);

        double total_amount = totalSum(monthly_fee, credit_term);
        new_str = QString("%1").arg(total_amount, 0, 'f', 2);
        ui->lineEdit_13->setText(new_str);

        double overpayment = overPay(total_amount, credit_amount);
        new_str = QString("%1").arg(overpayment, 0, 'f', 2);
        ui->lineEdit_12->setText(new_str);
    } else {
        double amount_month = difCreditAmountMonth(credit_amount, credit_term);
        double remain = credit_amount - amount_month;
        double diff_fee = diffPay(amount_month, remain, interest_rate, credit_term);
        QString new_str;
        new_str = QString("%1").arg(diff_fee, 0, 'f', 2);
        ui->lineEdit_11->setText(new_str);
        graphDialog = new GrapfDialog(this);
        graphDialog->show();
    }
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    isAnnuity = checked;
}


void MainWindow::on_pushButton_36_clicked()
{
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();

}

