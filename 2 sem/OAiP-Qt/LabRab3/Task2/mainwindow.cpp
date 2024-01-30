#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_outputButton_clicked()
{
    ui->output_first_matric->clear();
    ui->output_second_matric->clear();

    vector<pair<vector<int>, vector<pair<int, double>>>> v;

    for (int i = 0; i < ui->count_pair->value(); i++) {

        int intValue = qrand() % 100;
        int intValue2 = qrand() % 100;
        double doubleValue = static_cast<double>(qrand() % 100) / 50.4;

        vector<int> vec {intValue2};
        vector<pair<int, double>> secVec {make_pair(intValue, doubleValue)};

        v.push_back(make_pair(vec, secVec));
    }
    for (auto p : v) {
        ui->output_first_matric->append(" ");
        ui->output_second_matric->append(" ");
        for (auto x : p.first) {
            ui->output_first_matric->setAlignment(Qt::AlignHCenter);
            ui->output_first_matric->insertPlainText(QString::number(x) + " ");
        }
        for (auto x : p.second) {
            ui->output_second_matric->setAlignment(Qt::AlignHCenter);
            ui->output_second_matric->insertPlainText("(" + QString::number(x.first) + " , " + QString::number(x.second) + ") ");
        }
        ui->output_first_matric->append("");
        ui->output_second_matric->append("");
    }
}
