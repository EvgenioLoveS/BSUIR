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

vector <int> vec_a;
vector <int> vec_b = 0;

QString vectorToString(const vector<int>& vec)
{
    QString temp_output;
        for(size_t i = 0; i < vec_b.size(); ++i)
        {
            temp_output += QString::number(vec_b[i]) + " ";
        }
    return temp_output;
}

int getMedianOfThreeIntegers(long long firstNumber, long long secondNumber, long long thirdNumber) {
    if ((secondNumber <= firstNumber && firstNumber <= thirdNumber) || (thirdNumber <= firstNumber && firstNumber <= secondNumber)) {
        return firstNumber;
    } else if ((firstNumber <= secondNumber && secondNumber <= thirdNumber) || (thirdNumber <= secondNumber && secondNumber <= firstNumber)) {
        return secondNumber;
    } else {
        return thirdNumber;
    }
}

int getMedian(vector<int>& vec, size_t i)
{
    int median;
    if(i + 2 < vec.size())
    {
        median = getMedianOfThreeIntegers(vec[i], vec[i + 1], vec[i + 2]);
    }
    else if(i + 1 < vec.size())
    {
        median = (vec[i] + vec[i+1]) / 2;
    }
    else
    {
        median = vec[i];
    }
    return median;
}

void MainWindow::on_add_in_vector_clicked()
{
    int temp = ui->add_number->value();
    vec_a.emplace_back(temp);
}

void MainWindow::on_show_vector_clicked()
{
    QString output_vector;
    for(size_t i = 0; i < vec_a.size(); ++i)
    {
        output_vector += QString::number(vec_a[i]) + " ";
    }
    ui -> output_vec->insert(output_vector);
}

void MainWindow::on_clear_vector_clicked()
{
    vec_a.clear();
    vec_b.clear();
    ui->output_vec->clear();
    ui ->output_medians->clear();
}

void MainWindow::on_set_of_medians_clicked()
{
    if(vec_a.size() <= 1)
    {
        QMessageBox::warning(this, "Error", "Enter more elements.");
        return;
    }
    for(size_t i = 0; i < vec_a.size(); i+=3)
    {
        int median = getMedian(vec_a, i);
        vec_b.push_back(median);
    }
    QString temp_output = vectorToString(vec_b);
    ui -> output_medians->insert(temp_output);
}
