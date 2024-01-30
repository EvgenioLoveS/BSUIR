#include "mainwindow.h"
#include <QApplication>
#include <ctime>
#include <cstdlib>

#include <QWidget>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

#include <HashTableOpen.h>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем объекты серий для каждой таблицы
    QLineSeries *series16 = new QLineSeries();
    QLineSeries *series64 = new QLineSeries();
    QLineSeries *series128 = new QLineSeries();
    QLineSeries *series2048 = new QLineSeries();

    // Инициализируем таблицы
    HashTableOpen table16(16);
    HashTableOpen table64(64);
    HashTableOpen table128(128);
    HashTableOpen table2048(2048);

    // Замеряем время поиска в таблицах для каждого ключа
    for (int i = 1; i <= 500000; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        table16.search(i);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        series16->append(i, duration.count());


        start = std::chrono::high_resolution_clock::now();
        table64.search(i);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        series64->append(i, duration.count());

        start = std::chrono::high_resolution_clock::now();
        table128.search(i);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        series128->append(i, duration.count());

        start = std::chrono::high_resolution_clock::now();
        table2048.search(i);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        series2048->append(i, duration.count());
    }

    // Создаем ось значений и устанавливаем для нее название
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Time");

    // Создаем ось категорий и устанавливаем для нее название
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Key");

    // Создаем график и добавляем на него серии данных и оси
    QChart *chart = new QChart();
    chart->addSeries(series16);
    chart->addSeries(series64);
    chart->addSeries(series128);
    chart->addSeries(series2048);
    chart->setAxisX(axisX, series16);
    chart->setAxisY(axisY, series16);

    // Создаем окно и добавляем на него график
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Отображаем окно
    chartView->show();

    return a.exec();
}
