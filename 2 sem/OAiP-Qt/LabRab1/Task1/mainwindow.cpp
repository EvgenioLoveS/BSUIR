#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DATE.h"
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

bool MainWindow::CheckFile(QString date)
{
    if (date[2] != '.' || date[5] != '.' || date.length() != 10)
    {
        return false;
    }
    for(int i = 0; i < date.length(); ++i)
    {
        if ((date[i] > '9' || date[i] < '0') && date[i] != '.' )
        {
            return false;
        }
    }
    QString Day, Month, Year;
    for(int i = 0; i<10;i++)
    {
        if(i>-1 && i<2)
        {
            Day+=date[i];
        }
        if(i>2 && i<5)
        {
            Month+=date[i];
        }
        if(i>5)
        {
            Year+=date[i];
        }
    }
    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date ss(year,month,day);
    if (month > 12 || day > 31 || month < 0 || day< 0 || year > 9999 || year < 0)
    {
        return false;
    }
    if (!ss.isLeap() && month == 2 && day > 28)
    {
        return false;
    }
    if (ss.isLeap() && month == 2 && day > 29)
    {
        return false;
    }
    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        return false;
    }
    return true;
}

void MainWindow::on_OpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (!CheckFile(line))
        {
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        QDate date = date.fromString(line, "dd.MM.yyyy");
        ss = Date(date.year(), date.month(), date.day());
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QTableWidgetItem *itm = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
        ui->tableWidget->setItem(row,0,itm);
        QTableWidgetItem *itm1 = new QTableWidgetItem(ss.nextDay().str());
        ui->tableWidget->setItem(row,1,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(ss.previousDay().str());
        ui->tableWidget->setItem(row,2,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(ss.boolToString(ss.isLeap()));
        ui->tableWidget->setItem(row,3,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(ss.shortToString(ss.weekNumber()));
        ui->tableWidget->setItem(row,4,itm4);
        QTableWidgetItem *itm5 = new QTableWidgetItem(ss.intToString(ss.duration(ss)));
        ui->tableWidget->setItem(row,5,itm5);
        ui->tableWidget->update();
    }
    file.close();
    ui->tableWidget->setEditTriggers(0);
}

void MainWindow::on_SaveFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Сохранение"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
           return;
    }
    QTextStream out(&file);
    int row = ui->tableWidget->rowCount();
    for (int i = 0;i< row;i++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(ui->tableWidget->item(i,0)->text());
        out << itm->text() << '\n';
    }
    file.close();
}
void MainWindow::on_addDate_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    QDate date = ui->Date_Add_Text->date();
    ss = Date(date.year(),date.month(),date.day());
    QTableWidgetItem *itm = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
    ui->tableWidget->setItem(row,0,itm);
    QTableWidgetItem *itm1 = new QTableWidgetItem(ss.nextDay().str());
    ui->tableWidget->setItem(row,1,itm1);
    QTableWidgetItem *itm2 = new QTableWidgetItem(ss.previousDay().str());
    ui->tableWidget->setItem(row,2,itm2);
    QTableWidgetItem *itm3 = new QTableWidgetItem(ss.boolToString(ss.isLeap()));
    ui->tableWidget->setItem(row,3,itm3);
    QTableWidgetItem *itm4 = new QTableWidgetItem(ss.shortToString(ss.weekNumber()));
    ui->tableWidget->setItem(row,4,itm4);
    QTableWidgetItem *itm5 = new QTableWidgetItem(ss.intToString(ss.duration(ss)));
    ui->tableWidget->setItem(row,5,itm5);
    QFile file("save.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
            return;
    }
    QTextStream out(&file);
    out << itm->text()<<'\n';
    ui->tableWidget->update();
}

void MainWindow::on_changeDate_clicked()
{
    QDate d = ui->Date_Change_Text->date();
    ss = Date(d.year(),d.month(),d.day());
    int row = ui->Line_Number_Change->text().toInt()-1;
    if(row<0 || row>=ui->tableWidget->rowCount())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Введите правильный номер даты для изменения"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    QTableWidgetItem *itm = new QTableWidgetItem(d.toString("dd.MM.yyyy"));
    ui->tableWidget->setItem(row,0,itm);
    QTableWidgetItem *itm1 = new QTableWidgetItem(ss.nextDay().str());
    ui->tableWidget->setItem(row,1,itm1);
    QTableWidgetItem *itm2 = new QTableWidgetItem(ss.previousDay().str());
    ui->tableWidget->setItem(row,2,itm2);
    QTableWidgetItem *itm3 = new QTableWidgetItem(ss.boolToString(ss.isLeap()));
    ui->tableWidget->setItem(row,3,itm3);
    QTableWidgetItem *itm4 = new QTableWidgetItem(ss.shortToString(ss.weekNumber()));
    ui->tableWidget->setItem(row,4,itm4);
    QTableWidgetItem *itm5 = new QTableWidgetItem(ss.intToString(ss.duration(ss)));
    ui->tableWidget->setItem(row,5,itm5);
    QFile file("save.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
           return;
    }
    QTextStream out(&file);
    out << itm->text()<<'\n';
}

void MainWindow::on_Date_Birthday_Text_userDateChanged(const QDate &date)
{
    Date birthdaydate = Date(date.year(),date.month(),date.day());
    QDate today = today.currentDate();
    Date td = Date(today.year(),today.month(),today.day());
    ui->lcdNumber->display(td.daysTillYourBithday(birthdaydate));
}
