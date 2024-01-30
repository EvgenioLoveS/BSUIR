#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->output_of_vec1->setReadOnly(true);
    ui->output_of_vec2->setReadOnly(true);
    ui->Assign_output_1->setPlaceholderText("Кол-во");
    ui->Assign_output_2->setPlaceholderText("Значение");
    ui->At_output->setPlaceholderText("Индекс");
    ui->Emplace_output_1->setPlaceholderText("Индекс");
    ui->Emplace_output_2->setPlaceholderText("Значение");
    ui->Emplace_Back_output->setPlaceholderText("Значение");
    ui->Erase_output_1->setPlaceholderText("Начало");
    ui->Erase_output_2->setPlaceholderText("Конец");
    ui->Insert_output_1->setPlaceholderText("Индекс");
    ui->Insert_output_2->setPlaceholderText("Значение");
    ui->Push_Back_output->setPlaceholderText("Значение");
    ui->Reserve_output->setPlaceholderText("Значение");
    ui->Resize_output->setPlaceholderText("Значение");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generationVec1_clicked()
{
    vec1.clear();
    int size_of_vec1 = rand() % 20;
    for(int i = 0; i < size_of_vec1; ++i) vec1.push_back(rand()%20);
    output_of_vec1(vec1);
}

void MainWindow::on_generationVec2_clicked()
{
    vec2.clear();
    int size_of_vec2 = rand() % 20;
    for(int i = 0; i < size_of_vec2; ++i) vec2.push_back(rand()%20);
    output_of_vec2(vec2);
}

void MainWindow::output_of_vec1(vector<int> &temp_vec)
{
    QString line_of_output = "";
    for(size_t i = 0; i < temp_vec.size(); ++i){
        line_of_output += QString::number(temp_vec[i]) + " ";
    }
    ui->output_of_vec1->setText(line_of_output);
}

void MainWindow::output_of_vec2(vector<int> &temp_vec)
{
    QString line_of_output2 = "";
    for(size_t i = 0; i < temp_vec.size(); ++i) {
        line_of_output2 += QString::number(temp_vec[i]) + " ";
    }
    ui->output_of_vec2->setText(line_of_output2);
}

void MainWindow::on_EmptyMethods_clicked()
{
    QMessageBox::information(this, "Empty", QString::number(vec1.empty()));
}

void MainWindow::on_ClearMethods_clicked()
{
    vec1.clear();
    output_of_vec1(vec1);
}

void MainWindow::on_SizeMethods_clicked()
{
    QMessageBox::information(this, "Size", QString::number(vec1.size()));
}

void MainWindow::on_CapacityMethods_clicked()
{
    QMessageBox::information(this, "Capacity", QString::number(vec1.capacity()));
}

void MainWindow::on_DataMethods_clicked()
{
    QMessageBox::information(this, "Data", QString::number(*vec1.data()));
}

void MainWindow::on_Max_SizeMethods_clicked()
{
    QMessageBox::information(this, "Max_Size", QString::number(vec1.max_size()));
}

void MainWindow::on_SwapMethods_clicked()
{
    vec1.swap(vec2);
    output_of_vec1(vec1);
    output_of_vec2(vec2);
}

void MainWindow::on_BackMethods_clicked()
{
    int temp_back = vec1.back();
    QMessageBox::information(this, "Back", QString::number(temp_back));

}

void MainWindow::on_FrontMethods_clicked()
{
    QMessageBox::information(this, "Front", QString::number(vec1.front()));
}

void MainWindow::on_Pop_BackMethods_clicked()
{
    vec1.pop_back();
    output_of_vec1(vec1);
}

void MainWindow::on_Push_BackMethods_clicked()
{
    if(ui->Push_Back_output->text().isEmpty()) return;
    vec1.push_back(ui->Push_Back_output->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_AtMethods_clicked()
{
    if(ui->At_output->text().isEmpty()) return;
    int temp_At = vec1.at(ui->At_output->text().toInt());
    QMessageBox::information(this, "At", QString::number(temp_At));
}

void MainWindow::on_ReserveMethods_clicked()
{
    if(ui->Reserve_output->text().isEmpty()) return;
    vec1.reserve(ui->Reserve_output->text().toInt());
}

void MainWindow::on_ResizeMethods_clicked()
{
    if(ui->Resize_output->text().isEmpty()) return;
    vec1.resize(ui->Resize_output->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_AssignMethods_clicked()
{
    if(ui->Assign_output_1->text().isEmpty() || ui->Assign_output_2->text().isEmpty()) return;
    vec1.assign_from_4(ui->Assign_output_1->text().toInt(), ui->Assign_output_2->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_InsertMethods_clicked()
{
    if(ui->Insert_output_1->text().isEmpty() || ui->Insert_output_2->text().isEmpty()) return;
    vec1.insert_from_4(ui->Insert_output_1->text().toInt(), ui->Insert_output_2->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_EraseMethods_clicked()
{
    if(ui->Erase_output_1->text().isEmpty() || ui->Erase_output_2->text().isEmpty()) return;
    vec1.erase_from_4(ui->Erase_output_1->text().toInt(),ui->Erase_output_2->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_EmplaceMethods_clicked()
{
    if(ui->Emplace_output_1->text().isEmpty() || ui->Emplace_output_2->text().isEmpty()) return;
    vec1.emplace_from_4(ui->Emplace_output_1->text().toInt(), ui->Emplace_output_2->text().toInt());
    output_of_vec1(vec1);
}

void MainWindow::on_Emplace_BackMethods_clicked()
{
    if(ui->Emplace_Back_output->text().isEmpty()) return;
    vec1.emplace_back(ui->Emplace_Back_output->text().toInt());
    output_of_vec1(vec1);
}
